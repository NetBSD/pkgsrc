# $NetBSD: Makefile,v 1.8 2004/11/02 18:40:23 symka Exp $
#

DISTNAME=	nidentd-1.0
PKGREVISION=	2
CATEGORIES=	net sysutils
MASTER_SITES=	ftp://ftp.tgr.lubin.edu.pl/pub/NetBSD/nidentd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	symka@NetBSD.org
COMMENT=	identd that supports IPv4, IPv6, NAT, fake and random

DEPENDS+=	lsof>=4.61:../../sysutils/lsof

do-build:
		${SED} \
			-e 's,@LOCALBASE@,${LOCALBASE},' \
			<${WRKSRC}/nidentd >${WRKSRC}/nidentd.tmp
		${MV} ${WRKSRC}/nidentd.tmp ${WRKSRC}/nidentd

do-install:
		${INSTALL_DATA} ${WRKSRC}/nidentd.nat ${PREFIX}/etc/nidentd.nat.example ; \
		${INSTALL_DATA} ${WRKSRC}/nidentd.fake ${PREFIX}/etc/nidentd.fake.example ; \
		${INSTALL_SCRIPT} ${WRKSRC}/nidentd ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
