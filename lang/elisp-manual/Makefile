# $NetBSD: Makefile,v 1.7 2003/06/09 09:02:28 uebayasi Exp $

DISTNAME=	elisp-manual-21-2.8
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=emacs/}

MAINTAINER=	uebayasi@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/emacs/emacs.html
COMMENT=	The Emacs Lisp Reference Manual for GNU Emacs Version 20.3

GNU_CONFIGURE=	YES
TEXINFO_OVERRIDE=	YES

ALL_TARGET=	elisp

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
