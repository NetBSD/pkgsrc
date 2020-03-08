# $NetBSD: Makefile,v 1.34 2020/03/08 16:47:36 wiz Exp $

DISTNAME=	libctl-3.2.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://ab-initio.mit.edu/libctl/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://ab-initio.mit.edu/libctl/
COMMENT=	Guile-based flexible control file library for scientific simulations
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c fortran77

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
TEST_TARGET=	check

INSTALLATION_DIRS=	share/doc/libctl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} \
		AUTHORS ChangeLog COPYING COPYRIGHT INSTALL NEWS README.md \
		${DESTDIR}${PREFIX}/share/doc/libctl/

.include "../../lang/guile20/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
