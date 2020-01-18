# $NetBSD: Makefile,v 1.2 2020/01/18 23:35:09 rillig Exp $

DISTNAME=		merkletree-20140304
CATEGORIES=		security
MASTER_SITES=		# not used
DISTFILES=		# not used

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Library and utility to calculate merkle trees
LICENSE=		modified-bsd

AUTO_MKDIRS=		yes
GNU_CONFIGURE=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../security/libmultigest/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
