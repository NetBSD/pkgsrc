# $NetBSD: Makefile,v 1.7 2003/12/16 22:52:37 grant Exp $
#

DISTNAME=		docsis-0.9.0
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docsis/}

MAINTAINER=		symka@NetBSD.vejas.lt
HOMEPAGE=		http://docsis.sourceforge.net/
COMMENT=		Utility for manipulating DOCSIS-compliant cable modems

BUILD_DEPENDS+=		bison>=1.25:../../devel/bison

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		m4

.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
