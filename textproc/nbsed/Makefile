# $NetBSD: Makefile,v 1.8 2004/08/21 08:39:54 jlam Exp $

DISTNAME=		nbsed-20040821
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

.include "../../pkgtools/libnbcompat/inplace.mk"
.include "../../mk/bsd.pkg.mk"
