# $NetBSD: Makefile,v 1.10 2002/02/09 07:40:46 taca Exp $
#

DISTNAME=	chasen-${CHASEN_VERSION}
CATEGORIES=	japanese
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://chasen.aist-nara.ac.jp/
COMMENT=	ChaSen, Japanese Morphological Analysis System

DEPENDS+=	chasen-base>=${CHASEN_VERSION}:../../japanese/chasen-base
DEPENDS+=	ipadic>=2.4.1:../../japanese/ipadic

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
