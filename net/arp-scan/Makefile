# $NetBSD: Makefile,v 1.1.1.1 2012/01/08 15:14:23 wiz Exp $
#

DISTNAME=	arp-scan-1.8
CATEGORIES=	net
MASTER_SITES=	http://www.nta-monitor.com/tools/arp-scan/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nta-monitor.com/tools/arp-scan/
COMMENT=	Discovery and fingerprinting tool using ARP
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL=	arp-fingerprint get-iab get-oui

.include "../../mk/bsd.pkg.mk"
