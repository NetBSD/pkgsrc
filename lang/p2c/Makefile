# $NetBSD: Makefile,v 1.11 2009/09/03 13:14:10 joerg Exp $

DISTNAME=	p2c-1.20
CATEGORIES=	lang
MASTER_SITES=	ftp://csvax.cs.caltech.edu/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Pascal to C compiler (translates Pascal to C)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/src
CFLAGS+=	-Dunix=1

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
