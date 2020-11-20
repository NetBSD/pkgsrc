#	$NetBSD: Makefile,v 1.3 2020/11/20 05:55:02 riastradh Exp $

DISTNAME=	libfido2-1.5.0
PKGREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	${PKGBASE}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libfido2/
COMMENT=	U2F/FIDO/FIDO2 library and tools
LICENSE=	2-clause-bsd

USE_CMAKE=		yes
USE_LANGUAGES=		c
CONFIGURE_DIRS+=	build
CMAKE_ARG_PATH=		..
CMAKE_ARGS.NetBSD+=	-DBASE_LIBRARIES:STRING=usbhid

CHECK_PORTABILITY_SKIP+=	misc/hooks

pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../devel/libcbor/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
