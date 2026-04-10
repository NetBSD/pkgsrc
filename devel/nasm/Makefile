# $NetBSD: Makefile,v 1.73 2026/04/10 16:54:28 schwarz Exp $

DISTNAME=	nasm-3.01
CATEGORIES=	devel lang
MASTER_SITES=	https://www.nasm.us/pub/nasm/releasebuilds/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nasm.us/
COMMENT=	General-purpose x86 assembler
LICENSE=	2-clause-bsd

USE_LANGUAGE=		c
USE_CC_FEATURES=	c17
FORCE_C_STD=		c17

USE_TOOLS+=		gmake makeinfo perl gsed
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/nasm
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/nasm/html
CONFIGURE_ENV+=		ASCIIDOC=false
CONFIGURE_ENV+=		XMLTO=false

BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything
TEST_TARGET=		test

MAKE_FLAGS+=	PERL5=${PERL5:Q}
MAKE_FLAGS+=	INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}

CTF_SUPPORTED=	no # https://smartos.org/bugview/OS-6510

.include "../../mk/bsd.pkg.mk"
