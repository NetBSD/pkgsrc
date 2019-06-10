# $NetBSD: Makefile,v 1.9 2019/06/10 13:32:56 schmonz Exp $
#

GITHUB_PROJECT=	discount
DISTNAME=	v2.2.6
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/^v//}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=Orc/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://www.pell.portland.or.us/~orc/Code/discount/
COMMENT=	Markdown C implementation
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

HAS_CONFIGURE=		YES
CONFIGURE_SCRIPT=	./configure.sh
CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--execdir=${PREFIX}/bin
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--shared
CONFIGURE_ARGS+=	--enable-all-features

USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libmarkdown.pc.in

INSTALL_TARGET=		install.everything
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
