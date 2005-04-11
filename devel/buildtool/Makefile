# $NetBSD: Makefile,v 1.19 2005/04/11 21:45:18 tv Exp $
#

DISTNAME=	buildtool-0.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable build infrastructure

PKG_INSTALLATION_TYPES=	overwrite pkgviews

HAS_CONFIGURE=	yes

TEST_TARGET=		test

PKG_SYSCONFSUBDIR=	buildtool

CONFIGURE_ARGS=		-p ${PREFIX}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		SH="${SH}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/buildtool/pkgflags

.include "../../mk/bsd.pkg.mk"
