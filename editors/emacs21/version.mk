# $NetBSD: version.mk,v 1.4 2019/06/08 10:40:54 rillig Exp $

_EMACS_FLAVOR=		emacs
_EMACS_REQD=		emacs21>=21.4<22
_EMACS_PKGDEP.base=
_EMACS_PKGDEP.leim=	leim>=21.${EMACS_VERSION_MINOR}<22:../../editors/leim21

_EMACS_VERSION_MAJOR=	21
_EMACS_VERSION_MINOR=	4
