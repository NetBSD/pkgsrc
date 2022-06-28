# $NetBSD: Makefile,v 1.15 2022/06/28 11:34:58 wiz Exp $
#

DISTNAME=	arp-scan-1.9
PKGREVISION=	7
CATEGORIES=	net
MASTER_SITES=	http://www.nta-monitor.com/files/arp-scan/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.nta-monitor.com/tools-resources/security-tools/arp-scan
COMMENT=	Discovery and fingerprinting tool using ARP
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL=	arp-fingerprint get-iab get-oui

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
