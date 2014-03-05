# $NetBSD: Makefile,v 1.1.1.1 2014/03/05 05:09:44 agc Exp $

DISTNAME=		multigest-20140303
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
