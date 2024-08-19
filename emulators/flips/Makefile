# $NetBSD: Makefile,v 1.1 2024/08/19 13:19:39 wiz Exp $

DISTNAME=	Flips-181
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=Alcaro/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Alcaro/Flips/
COMMENT=	Patcher for IPS and BPS files
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/${DISTNAME}

CHECK_PORTABILITY_SKIP=	libdivsufsort-2.0.1/configure

INSTALLATION_DIRS=	bin

# For GTK GUI support, add "-DFLIPS_GTK -lgtk3"
do-build:
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV} ${CXX} ${CXXFLAGS} *.c *.cpp -o flips

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flips ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
