# $NetBSD: Makefile,v 1.1 2019/10/06 23:00:09 kamil Exp $

DISTNAME=	tcl-theo-0.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=krytarowski/}

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/krytarowski/tcl-theo/
COMMENT=	theo.c implementation for Tcl
LICENSE=	2-clause-bsd

EXTRACT_USING=	bsdtar

USE_TOOLS+=	autoreconf autoconf

GNU_CONFIGURE=	yes

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/bsd.pkg.mk"
