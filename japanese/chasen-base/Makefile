# $NetBSD: Makefile,v 1.6 2001/04/26 01:46:32 taca Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}${CHASEN_NBVERSION}
CATEGORIES=		japanese
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/chasen/

PATCHFILES=		chasen-2.2.6-nmz-2.diff
PATCH_SITES=		${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://chasen.aist-nara.ac.jp/
COMMENT=		ChaSen, Japanese Morphological Analysis System

GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

post-install:
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/chasen/dic

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
