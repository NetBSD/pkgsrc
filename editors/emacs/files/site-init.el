;; $NetBSD: site-init.el,v 1.1.1.1 2003/04/11 00:34:25 uebayasi Exp $

;; NetBSD puts info files in /usr/share.
(setq Info-default-directory-list
      (cons "/usr/share/info/"
	    Info-default-directory-list))

(autoload 'send-pr "/usr/share/gnats/send-pr.el" 
  "Command to create and send a problem report." t)
