# $NetBSD: Makefile,v 1.5 2020/04/03 22:06:17 wiz Exp $

DISTNAME=	fdupes-1.51
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://fdupes.googlecode.com/files/

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	http://netdial.caribe.net/~adrian2/fdupes.html
COMMENT=	Program for identifying or deleting duplicate files
LICENSE=	mit

USE_LANGUAGES=	c
NO_CONFIGURE=	yes

MAKE_FLAGS=	INSTALLDIR=${PREFIX}/bin

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
