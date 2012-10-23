# $NetBSD: Makefile,v 1.3 2012/10/23 17:18:10 asau Exp $
#

DISTNAME=	arp-scan-1.8
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.nta-monitor.com/tools/arp-scan/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nta-monitor.com/tools/arp-scan/
COMMENT=	Discovery and fingerprinting tool using ARP
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL=	arp-fingerprint get-iab get-oui

.include "../../mk/bsd.pkg.mk"
