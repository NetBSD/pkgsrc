#	$NetBSD: Makefile,v 1.1 2020/08/19 16:25:56 riastradh Exp $

DISTNAME=	libfido2-1.4.0
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libfido2/
COMMENT=	U2F/FIDO/FIDO2 library and tools
LICENSE=	2-clause-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c

CONFIGURE_DIRS+=	build
CMAKE_ARG_PATH=		..

CMAKE_ARGS.NetBSD+=	-DBASE_LIBRARIES:STRING=usbhid

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/libcbor/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
