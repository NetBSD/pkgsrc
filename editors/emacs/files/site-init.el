;; $NetBSD: site-init.el,v 1.2 2003/04/12 10:16:39 uebayasi Exp $

;; NetBSD puts info files in /usr/share.
(setq Info-default-directory-list
      (cons "/usr/share/info/"
	    Info-default-directory-list))

(autoload 'send-pr "/usr/share/gnats/send-pr.el" 
  "Command to create and send a problem report." t)
