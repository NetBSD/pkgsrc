# $NetBSD: Makefile,v 1.9 2001/09/09 05:14:46 jlam Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}
CATEGORIES=		japanese
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/chasen/

PATCHFILES=		chasen-${CHASEN_VERSION}-nmz.diff
PATCH_SITES=		${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://chasen.aist-nara.ac.jp/
COMMENT=		ChaSen, Japanese Morphological Analysis System

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined
USE_BUILDLINK_ONLY=	# defined

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/chasen/dic

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
