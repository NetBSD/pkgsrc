# $NetBSD: Makefile,v 1.25 2023/01/18 16:49:07 wiz Exp $

DISTNAME=	firewalk-5.0
PKGREVISION=	4
CATEGORIES=	net security
#MASTER_SITES=	http://www.packetfactory.net/firewalk/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://packetfactory.openwall.net/projects/firewalk/
COMMENT=	Determines the filter rules on a packet forwarding device
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/Firewalk
GNU_CONFIGURE=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man8

.include "../../devel/libnet11/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/firewalk.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
