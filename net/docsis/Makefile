# $NetBSD: Makefile,v 1.14 2005/07/02 13:03:53 symka Exp $
#

DISTNAME=		docsis-0.9.4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docsis/}

MAINTAINER=		symka@NetBSD.org
HOMEPAGE=		http://docsis.sourceforge.net/
COMMENT=		Utility for manipulating DOCSIS-compliant cable modems

BUILD_DEPENDS+=		bison>=1.25:../../devel/bison

GNU_CONFIGURE=		YES
USE_TOOLS+=		gm4

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
