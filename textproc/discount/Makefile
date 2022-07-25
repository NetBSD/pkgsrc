# $NetBSD: Makefile,v 1.13 2022/07/25 11:12:29 wiz Exp $

DISTNAME=	discount-2.2.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Orc/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://www.pell.portland.or.us/~orc/Code/discount/
COMMENT=	Markdown C implementation
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

CONFLICTS+=		multimarkdown-[0-9]*

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--execdir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--shared
CONFIGURE_ARGS+=	--enable-all-features

USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libmarkdown.pc.in

INSTALL_TARGET=		install.everything
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
