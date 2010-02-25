# $NetBSD: Makefile,v 1.3 2010/02/25 20:21:44 wiz Exp $

DISTNAME=	ddrescue-1.11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=ddrescue/}

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	http://www.gnu.org/software/ddrescue/ddrescue.html
COMMENT=	GNU ddrescue is a data recovery tool
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		YES
USE_LANGUAGES=		c++
INFO_FILES=		YES

CONFIGURE_ARGS+=	CC=${CC:Q} CXX=${CXX:Q} CPPFLAGS=${CPPFLAGS:Q}
CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:Q} CXXFLAGS=${CXXFLAGS:Q}
CONFIGURE_ARGS+=	LDFLAGS=${LDFLAGS:Q}
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

TEST_TARGET=		check
INSTALL_TARGET=		install install-man

.include "../../mk/bsd.pkg.mk"
