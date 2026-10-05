# $NetBSD: Makefile,v 1.1 2026/10/05 13:10:40 ktnb Exp $

DISTNAME=	usrsctp-0.9.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sctplab/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sctplab/usrsctp/
COMMENT=	Portable SCTP userland stack
LICENSE=	modified-bsd

PKGCONFIG_OVERRIDE+=	usrsctp.pc.in

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
