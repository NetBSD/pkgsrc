# $NetBSD: Makefile,v 1.41 2026/10/13 17:54:19 gdt Exp $

VERSION=	4.7.1
DISTNAME=	libctl-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=NanoComp/}
GITHUB_RELEASE=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://libctl.readthedocs.io/en/latest/
COMMENT=	Guile-based flexible control file library for scientific simulations
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c fortran77

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
TEST_TARGET=	check

INSTALLATION_DIRS=	share/doc/libctl

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/docs/*.md ${DESTDIR}${PREFIX}/share/doc/libctl/
	cd ${WRKSRC} && ${INSTALL_DATA} \
		AUTHORS COPYING COPYRIGHT NEWS.md README.md \
		${DESTDIR}${PREFIX}/share/doc/libctl/

.include "../../lang/guile30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
