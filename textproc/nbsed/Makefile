# $NetBSD: Makefile,v 1.7 2004/07/25 05:42:30 grant Exp $

DISTNAME=		nbsed-20040725
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
