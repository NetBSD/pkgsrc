# $NetBSD: Makefile,v 1.1.1.1 2002/03/27 22:25:18 hubertf Exp $
#

DISTNAME=	nidentd-0.3
CATEGORIES=	net sysutils
MASTER_SITES=	ftp://ftp.arhea.net/pub/NetBSD/nidentd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
COMMENT=	identd that supports IPv4, IPv6 and NAT

DEPENDS+=	lsof-*:../../sysutils/lsof

WRKSRC=		${WRKDIR}/nidentd

do-build:
		${SED} \
			-e 's,@LOCALBASE@,${LOCALBASE},' \
			<${WRKSRC}/nidentd.sh >${WRKSRC}/nidentd

do-install:
		${INSTALL_DATA} ${WRKSRC}/identn.conf ${PREFIX}/etc/nidentd.conf.example ; \
		${INSTALL_SCRIPT} ${WRKSRC}/nidentd ${PREFIX}/libexec

.include "../../mk/bsd.pkg.mk"
