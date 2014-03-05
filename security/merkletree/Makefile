# $NetBSD: Makefile,v 1.1.1.1 2014/03/05 05:19:25 agc Exp $

DISTNAME=		merkletree-20140304
CATEGORIES=		security
MASTER_SITES=		# not used
DISTFILES=		# not used

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Library and utility to calculate merkle trees
LICENSE=		modified-bsd

AUTO_MKDIRS=		yes
GNU_CONFIGURE=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../security/libmultigest/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
