# $NetBSD: Makefile,v 1.8 2004/04/25 08:21:05 snj Exp $
#

DISTNAME=		docsis-0.9.0
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
