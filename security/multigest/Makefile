# $NetBSD: Makefile,v 1.3 2020/01/18 23:35:09 rillig Exp $

DISTNAME=		multigest-20150211
CATEGORIES=		security
MASTER_SITES=		# not used
DISTFILES=		# not used

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://www.NetBSD.org/
COMMENT=		Library and utility to calculate multiple message digests
LICENSE=		modified-bsd

AUTO_MKDIRS=		yes
GNU_CONFIGURE=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
