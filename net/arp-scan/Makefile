# $NetBSD: Makefile,v 1.4 2013/05/31 12:41:31 wiz Exp $
#

DISTNAME=	arp-scan-1.8
PKGREVISION=	2
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
