# $NetBSD: Makefile,v 1.6 2004/01/20 12:22:19 agc Exp $
#

DISTNAME=	ip6_int
PKGNAME=	${DISTNAME}-1.0
CATEGORIES=	net
MASTER_SITES=	http://www.bieringer.de/linux/IPv6/tools/
EXTRACT_SUFX=	#

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Convert an IPv4/IPv6 address to an in-addr.arpa/ip6.int PTR value

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

WRKSRC=		${WRKDIR}
USE_PERL5=	yes
REPLACE_PERL=	ip6_int
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ip6_int ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
