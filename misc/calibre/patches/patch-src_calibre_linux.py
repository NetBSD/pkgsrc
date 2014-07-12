$NetBSD: patch-src_calibre_linux.py,v 1.4 2014/07/12 15:48:02 wiz Exp $

Lifted from ArchLinux, saves mime and desktop files on disk
instead of trying to add them directly.

See https://www.archlinux.org/packages/community/x86_64/calibre/ ->
https://projects.archlinux.org/svntogit/community.git/tree/trunk?h=packages/calibre ->
https://projects.archlinux.org/svntogit/community.git/plain/trunk/desktop_integration.patch?h=packages/calibre

--- src/calibre/linux.py.orig	2014-07-11 02:19:43.000000000 +0000
+++ src/calibre/linux.py
@@ -644,18 +644,6 @@ class PostInstall:
             self.setup_completion()
         if islinux or isbsd:
             self.setup_desktop_integration()
-        self.create_uninstaller()
-
-        from calibre.utils.config import config_dir
-        if os.path.exists(config_dir):
-            os.chdir(config_dir)
-            if islinux or isbsd:
-                for f in os.listdir('.'):
-                    if os.stat(f).st_uid == 0:
-                        import shutil
-                        shutil.rmtree(f) if os.path.isdir(f) else os.unlink(f)
-                if os.stat(config_dir).st_uid == 0:
-                    os.rmdir(config_dir)
 
         if warn is None and self.warnings:
             self.info('\n\nThere were %d warnings\n'%len(self.warnings))
@@ -729,56 +717,39 @@ class PostInstall:
 
             with TemporaryDirectory() as tdir, CurrentDir(tdir), \
                                 PreserveMIMEDefaults():
-                render_img('mimetypes/lrf.png', 'calibre-lrf.png')
-                cc('xdg-icon-resource install --noupdate --context mimetypes --size 128 calibre-lrf.png application-lrf', shell=True)
-                self.icon_resources.append(('mimetypes', 'application-lrf', '128'))
-                cc('xdg-icon-resource install --noupdate --context mimetypes --size 128 calibre-lrf.png text-lrs', shell=True)
-                self.icon_resources.append(('mimetypes', 'application-lrs',
-                '128'))
-                render_img('mimetypes/mobi.png', 'calibre-mobi.png')
-                cc('xdg-icon-resource install --noupdate --context mimetypes --size 128 calibre-mobi.png application-x-mobipocket-ebook', shell=True)
-                self.icon_resources.append(('mimetypes', 'application-x-mobipocket-ebook', '128'))
-                render_img('mimetypes/tpz.png', 'calibre-tpz.png')
-                cc('xdg-icon-resource install --noupdate --context mimetypes --size 128 calibre-tpz.png application-x-topaz-ebook', shell=True)
-                self.icon_resources.append(('mimetypes', 'application-x-topaz-ebook', '128'))
-                render_img('mimetypes/azw2.png', 'calibre-azw2.png')
-                cc('xdg-icon-resource install --noupdate --context mimetypes --size 128 calibre-azw2.png application-x-kindle-application', shell=True)
-                self.icon_resources.append(('mimetypes', 'application-x-kindle-application', '128'))
-                render_img('mimetypes/azw3.png', 'calibre-azw3.png')
-                cc('xdg-icon-resource install --noupdate --context mimetypes --size 128 calibre-azw3.png application-x-mobi8-ebook', shell=True)
-                self.icon_resources.append(('mimetypes', 'application-x-mobi8-ebook', '128'))
-                render_img('lt.png', 'calibre-gui.png', width=256, height=256)
-                cc('xdg-icon-resource install --noupdate --size 256 calibre-gui.png calibre-gui', shell=True)
-                self.icon_resources.append(('apps', 'calibre-gui', '256'))
-                render_img('viewer.png', 'calibre-viewer.png', width=256, height=256)
-                cc('xdg-icon-resource install --size 256 calibre-viewer.png calibre-viewer', shell=True)
-                self.icon_resources.append(('apps', 'calibre-viewer', '256'))
-                render_img('tweak.png', 'calibre-ebook-edit.png', width=256, height=256)
-                cc('xdg-icon-resource install --size 256 calibre-ebook-edit.png calibre-ebook-edit', shell=True)
+                dir = os.path.join(self.opts.staging_sharedir,'../pixmaps')
+                os.mkdir(dir)
+                render_img('mimetypes/lrf.png', os.path.join(dir,'calibre-lrf.png'))
+                render_img('lt.png', os.path.join(dir, 'calibre-gui.png'))
+                render_img('viewer.png', os.path.join(dir, 'calibre-viewer.png'))
+                render_img('tweak.png', os.path.join(dir, 'calibre-ebook-edit.png'))
                 self.icon_resources.append(('apps', 'calibre-ebook-edit', '256'))
 
                 mimetypes = set([])
                 for x in all_input_formats():
                     mt = guess_type('dummy.'+x)[0]
-                    if mt and 'chemical' not in mt and 'ctc-posml' not in mt:
+                    if mt and 'chemical' not in mt and 'text' not in mt and 'pdf' not in mt and 'xhtml' not in mt:
                         mimetypes.add(mt)
 
                 def write_mimetypes(f):
                     f.write('MimeType=%s;\n'%';'.join(mimetypes))
 
                 from calibre.ebooks.oeb.polish.main import SUPPORTED
-                f = open('calibre-lrfviewer.desktop', 'wb')
+                dir = os.path.join(self.opts.staging_sharedir,'../applications')
+                os.mkdir(dir)
+                f = open(os.path.join(dir, 'calibre-lrfviewer.desktop'), 'wb')
+                
                 f.write(VIEWER)
                 f.close()
-                f = open('calibre-ebook-viewer.desktop', 'wb')
+                f = open(os.path.join(dir, 'calibre-ebook-viewer.desktop'), 'wb')
                 f.write(EVIEWER)
                 write_mimetypes(f)
-                f = open('calibre-ebook-edit.desktop', 'wb')
+                f = open(os.path.join(dir, 'calibre-ebook-edit.desktop'), 'wb')
                 f.write(ETWEAK)
                 mt = [guess_type('a.' + x.lower())[0] for x in SUPPORTED]
                 f.write('MimeType=%s;\n'%';'.join(mt))
                 f.close()
-                f = open('calibre-gui.desktop', 'wb')
+                f = open(os.path.join(dir, 'calibre-gui.desktop'), 'wb')
                 f.write(GUI)
                 write_mimetypes(f)
                 f.close()
