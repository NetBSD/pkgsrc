# $NetBSD: Makefile,v 1.23 2008/06/20 01:09:12 joerg Exp $
#

DISTNAME=	buildtool-0.16
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=buildtool/}

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://buildtool.sourceforge.net/
COMMENT=	Portable build infrastructure

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes

# The self test does not work unless the package is installed.
#TEST_TARGET=		test

PKG_SYSCONFSUBDIR=	buildtool

CONFIGURE_ARGS+=	-p ${PREFIX}
CONFIGURE_ARGS+=	-c ${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	-M ${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		SH=${SH:Q}

REQD_DIRS+=		share/buildtool/pkgflags

.include "../../mk/bsd.pkg.mk"
