# $NetBSD: Makefile,v 1.9 2004/07/10 12:37:20 grant Exp $
#

DISTNAME=		docsis-0.9.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docsis/}

MAINTAINER=		symka@NetBSD.vejas.lt
HOMEPAGE=		http://docsis.sourceforge.net/
COMMENT=		Utility for manipulating DOCSIS-compliant cable modems

BUILD_DEPENDS+=		bison>=1.25:../../devel/bison

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		m4

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
