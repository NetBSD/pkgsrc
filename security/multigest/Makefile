# $NetBSD: Makefile,v 1.2 2015/02/12 01:57:57 agc Exp $

DISTNAME=		multigest-20150211
CATEGORIES=		security
MASTER_SITES=		# not used
DISTFILES=		# not used

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		Library and utility to calculate multiple message digests
LICENSE=		modified-bsd

AUTO_MKDIRS=		yes
GNU_CONFIGURE=		yes

do-extract:
	${CP} -R ${FILESDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
