# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 19:01:25 jlam Exp $
#

DISTNAME=	chasen-${CHASEN_VERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
HOMEPAGE=	http://chasen.aist-nara.ac.jp/
COMMENT=	ChaSen, Japanese Morphological Analysis System

DEPENDS+=	chasen-base>=${CHASEN_VERSION}:../../textproc/chasen-base
DEPENDS+=	ipadic>=2.4.1:../../textproc/ipadic

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	# defined
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	# empty

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
