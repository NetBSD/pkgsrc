# $NetBSD: Makefile,v 1.2 2002/03/27 23:43:48 sommerfeld Exp $
#

DISTNAME=	nidentd-0.3
CATEGORIES=	net sysutils
MASTER_SITES=	ftp://ftp.arhea.net/pub/NetBSD/nidentd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
COMMENT=	identd that supports IPv4, IPv6 and NAT

BROKEN=		Distfile checksum mismatch.  
BROKEN+= 	Extreme inefficiency enables DoS attacks, particularly when running as root.

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
