# $NetBSD: version.mk,v 1.2 2019/06/08 10:41:00 rillig Exp $

_EMACS_FLAVOR=		xemacs
_EMACS_REQD=		xemacs>=21.4<21.5
_EMACS_PKGDEP.base=	xemacs-packages>=1.15:../../editors/xemacs-packages
_EMACS_PKGDEP.leim=

_EMACS_VERSION_MAJOR=	21
_EMACS_VERSION_MINOR=	4
