# $NetBSD: Makefile,v 1.17 2004/04/26 16:49:17 minskim Exp $
#

DISTNAME=	buildtool-0.15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable build infrastructure

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
HAS_CONFIGURE=	yes

TEST_TARGET=		test

PKG_SYSCONFSUBDIR=	buildtool

CONFIGURE_ARGS=		-p ${PREFIX}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		SH="${SH}"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/buildtool-0/pkgflags

.include "../../mk/bsd.pkg.mk"
