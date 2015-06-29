# $NetBSD: Makefile,v 1.13 2015/06/29 11:06:49 ryoon Exp $
#

DISTNAME=	chasen-${CHASEN_VERSION}
CATEGORIES=	japanese textproc
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://chasen-legacy.osdn.jp/
COMMENT=	Meta package of ChaSen, Japanese Morphological Analysis System

META_PACKAGE=		yes

DEPENDS+=	chasen-base>=${CHASEN_VERSION}:../../textproc/chasen-base
DEPENDS+=	ipadic>=2.6.3:../../textproc/ipadic

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
