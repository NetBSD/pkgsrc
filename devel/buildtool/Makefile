# $NetBSD: Makefile,v 1.20 2005/12/05 20:50:02 rillig Exp $
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

CONFIGURE_ARGS+=	-p ${PREFIX}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		SH=${SH:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/buildtool/pkgflags

.include "../../mk/bsd.pkg.mk"
