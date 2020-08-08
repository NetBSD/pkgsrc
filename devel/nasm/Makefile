# $NetBSD: Makefile,v 1.64 2020/08/08 18:35:10 nia Exp $

DISTNAME=	nasm-2.15.03
CATEGORIES=	devel lang
MASTER_SITES=	http://www.nasm.us/pub/nasm/releasebuilds/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nasm.us/
COMMENT=	General-purpose x86 assembler
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc
TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

USE_TOOLS+=		gmake makeinfo perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/nasm
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/nasm/html

BUILD_TARGET=		everything
INSTALL_TARGET=		install_everything
TEST_TARGET=		test

MAKE_FLAGS+=	PERL5=${PERL5:Q}
MAKE_FLAGS+=	INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=	INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}

CTF_SUPPORTED=	no # https://smartos.org/bugview/OS-6510

.include "../../mk/bsd.pkg.mk"
