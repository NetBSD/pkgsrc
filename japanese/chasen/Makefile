# $NetBSD: Makefile,v 1.8 2001/04/27 06:13:27 taca Exp $
#

DISTNAME=		chasen-${CHASEN_VERSION}
CATEGORIES=		japanese
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://chasen.aist-nara.ac.jp/
COMMENT=		ChaSen, Japanese Morphological Analysis System

DEPENDS+=		chasen-base>=2.2.1:../../japanese/chasen-base
DEPENDS+=		ipadic>=2.4.1:../../japanese/ipadic

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:		# empty

.include "../chasen-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
