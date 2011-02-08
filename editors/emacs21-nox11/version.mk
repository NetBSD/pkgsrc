# $NetBSD: version.mk,v 1.2 2011/02/08 13:20:14 hiramatsu Exp $

_EMACS_FLAVOR=	emacs
_EMACS_REQD=	emacs-nox11>=21.4<22
_EMACS_PKGDEP.base=
_EMACS_PKGDEP.leim=	leim>=21.${EMACS_VERSION_MINOR}<22:../../editors/leim21

_EMACS_VERSION_MAJOR=	21
_EMACS_VERSION_MINOR=	4
