# $NetBSD: Makefile,v 1.4 2001/02/25 04:17:53 hubertf Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
PKGNAME=		chasen-base-${CHASEN_VERSION}
CATEGORIES=		japanese
MASTER_SITES=		http://chasen.aist-nara.ac.jp/stable/chasen/

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
