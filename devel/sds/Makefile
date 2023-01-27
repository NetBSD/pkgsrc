# $NetBSD: Makefile,v 1.1 2023/01/27 10:30:49 micha Exp $

DISTNAME=	sds-2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcorporation/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/jcorporation/sds/
COMMENT=	Simple dynamic strings library for C
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c99
USE_LIBTOOL=	yes

TEST_TARGET=	test

INSTALLATION_DIRS=	lib/pkgconfig

post-extract:
	${CP} ${FILESDIR}/libsds-2.pc.in ${WRKDIR}
	cd ${WRKDIR} && ${SED} -e "s,@prefix@,${PREFIX},g" \
            -e "s,@release@,${PKGVERSION_NOREV},g" <libsds-2.pc.in >libsds-2.pc

post-install:
	cd ${WRKDIR} && ${INSTALL_DATA} libsds-2.pc \
            ${DESTDIR}${PREFIX}/lib/pkgconfig/libsds-2.pc

.include "../../mk/bsd.pkg.mk"
