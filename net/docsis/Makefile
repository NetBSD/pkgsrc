# $NetBSD: Makefile,v 1.22 2023/10/24 22:10:14 wiz Exp $
#

DISTNAME=		docsis-0.9.4
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docsis/}

MAINTAINER=		symka@NetBSD.org
HOMEPAGE=		http://docsis.sourceforge.net/
COMMENT=		Utility for manipulating DOCSIS-compliant cable modems

GNU_CONFIGURE=		YES
USE_TOOLS+=		gm4 bison

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
