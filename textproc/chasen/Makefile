# $NetBSD: Makefile,v 1.16 2025/11/28 07:26:27 wiz Exp $

DISTNAME=	chasen-${CHASEN_VERSION}
CATEGORIES=	textproc japanese
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	https://github.com/kazuma-t/chasen
COMMENT=	Meta package of ChaSen, Japanese Morphological Analysis System

META_PACKAGE=		yes

DEPENDS+=	chasen-base>=${CHASEN_VERSION}:../../textproc/chasen-base
DEPENDS+=	ipadic>=2.6.3:../../textproc/ipadic

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
