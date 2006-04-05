# $NetBSD: Makefile,v 1.13 2006/04/05 23:01:15 jlam Exp $

DISTNAME=	eukleides.1.0.1
PKGNAME=	eukleides-1.0.1
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://perso.wanadoo.fr/obrecht/download/

MAINTAINER=	tsadowski@gmx.net
HOMEPAGE=	http://perso.wanadoo.fr/obrecht/
COMMENT=	Euclidean geometry drawing language

DEPENDS+=	pstoedit>=3.31:../../graphics/pstoedit

BUILD_TARGET=	eukleides
USE_TOOLS+=	bison gmake makeinfo
INFO_FILES=	# PLIST

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS}					\
			BIN=${PREFIX:Q}/bin/				\
			INFO=${PREFIX:Q}/${PKGINFODIR:Q}/		\
			MAN=${PREFIX:Q}/${PKGMANDIR:Q}/man1/

.include "../../mk/bsd.pkg.mk"
