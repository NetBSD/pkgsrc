# $NetBSD: Makefile,v 1.6 2014/05/29 23:37:02 wiz Exp $
#

DISTNAME=	arp-scan-1.8
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.nta-monitor.com/tools/arp-scan/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nta-monitor.com/tools/arp-scan/
COMMENT=	Discovery and fingerprinting tool using ARP
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL=	arp-fingerprint get-iab get-oui

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
