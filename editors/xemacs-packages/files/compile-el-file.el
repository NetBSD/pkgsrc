;; $NetBSD: compile-el-file.el,v 1.1 2015/09/30 10:11:45 hauke Exp $

;; When bootstrapping the xemacs packages, set up load-path to include
;; the package elisp files, wherever pkgsrc has extracted them.
;;
;; Here There Be Dragons:
;; As upstream has pointed out, large scale byte-compiling would require
;; proper dependency management. What we do here should be safe enough 
;; for minor patches, but be aware of the problem.

(defun add-subdirs-to-load-path (basedir)

  "Add all first level dirs below basedir to load-path."

  (dolist (f (directory-files basedir))
    (let ((name (concat basedir "/" f)))
      (when (and (file-directory-p name)
		 (not (member f '("." "..")))
		 (add-to-list 'load-path name))))

    (add-to-list 'load-path basedir)))


(defun compile-el-file (basedir el-file)

  "With a given base path, set up load-path, and byte compile an elisp 
   source file."

  (add-subdirs-to-load-path basedir)
  (byte-compile-file el-file))
