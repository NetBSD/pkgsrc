;; $NetBSD: site-init.el,v 1.1 2002/05/02 20:21:31 drochner Exp $

;; NetBSD puts info files in /usr/share.
(setq Info-default-directory-list
      (cons "/usr/share/info/"
	    Info-default-directory-list))

(autoload 'send-pr "/usr/share/gnats/send-pr.el" 
  "Command to create and send a problem report." t)
