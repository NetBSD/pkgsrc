# $NetBSD: version.mk,v 1.3 2019/06/08 10:40:54 rillig Exp $

_EMACS_FLAVOR=		emacs
_EMACS_REQD=		emacs20>=20.7<21
_EMACS_PKGDEP.base=
_EMACS_PKGDEP.leim=	leim>=20.${EMACS_VERSION_MINOR}<21:../../editors/leim20

_EMACS_VERSION_MAJOR=	20
_EMACS_VERSION_MINOR=	7
