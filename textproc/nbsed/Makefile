# $NetBSD: Makefile,v 1.5 2004/06/12 05:18:31 minskim Exp $

DISTNAME=		nbsed-20040612
CATEGORIES=		textproc pkgtools
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/
COMMENT=		NetBSD-current's sed(1)

NO_CHECKSUM=		# defined

GNU_CONFIGURE=		# defined

post-extract:
	${MKDIR} ${WRKSRC}
	cd ${FILESDIR} && ${PAX} -rwpe . ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
