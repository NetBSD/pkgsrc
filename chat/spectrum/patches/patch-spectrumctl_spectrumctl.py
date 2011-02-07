$NetBSD: patch-spectrumctl_spectrumctl.py,v 1.1.1.1 2011/02/07 06:31:22 schnoebe Exp $

Modify to allow the path to the spectrum directory to be substituted in.
Modify to allow the name of the spectrum user to be substituted in.

--- spectrumctl/spectrumctl.py.orig	2010-08-12 15:18:20.000000000 +0000
+++ spectrumctl/spectrumctl.py
@@ -3,7 +3,7 @@
 #
 # spectrumctl can be used to control your spectrum-instances. Valid actions are
 # start, stop, restart and reload. By default, spectrumctl acts on all instances
-# defined in /etc/spectrum/
+# defined in @ETC_SPECTRUM@
 #
 # Copyright (C) 2009, 2010 Mathias Ertl
 #
@@ -29,12 +29,12 @@ from optparse import *
 cmds = [ x.name for x in doc.cmds ]
 description='''spectrumctl can be used to control your spectrum-instances.
 Valid actions are %s and %s. By default, spectrumctl acts on all transports
-defined in /etc/spectrum/.'''%( ', '.join( cmds[:-1] ), cmds[-1]  )
+defined in @ETC_SPECTRUM@.'''%( ', '.join( cmds[:-1] ), cmds[-1]  )
 
 parser = OptionParser( usage='Usage: %prog [options] action', version='0.2', description=description)
 parser.add_option( '-c', '--config', metavar='FILE',
 	help = 'Only act on transport configured in FILE (ignored for list)' )
-parser.add_option( '-d', '--config-dir', metavar='DIR', default='/etc/spectrum',
+parser.add_option( '-d', '--config-dir', metavar='DIR', default='@ETC_SPECTRUM@',
 	help = 'Act on all transports configured in DIR (default: %default)' )
 parser.add_option( '-q', '--quiet', action='store_true', default=False,
 	help = 'Do not print any output' )
@@ -51,8 +51,8 @@ parser.add_option_group( list_group )
 start_group = OptionGroup( parser, 'Options for action "start"' )
 start_group.add_option( '--su', # NOTE: the default is set by 
 	# spectrum.get_uid(). We need this so we can distinguish between
-	# actually setting --su=spectrum and setting nothing at all.
-	help = 'Start spectrum as this user (default: spectrum)' )
+	# actually setting --su=@SPECTRUM_USER@ and setting nothing at all.
+	help = 'Start spectrum as this user (default: @SPECTRUM_USER@)' )
 start_group.add_option( '--no-daemon', action='store_true', default=False,
 	help = 'Do not start spectrum in daemon mode' )
 start_group.add_option( '--debug', action='store_true', default=False,
