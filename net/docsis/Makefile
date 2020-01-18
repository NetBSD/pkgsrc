# $NetBSD: Makefile,v 1.19 2020/01/18 21:50:11 jperkin Exp $
#

DISTNAME=		docsis-0.9.4
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docsis/}

MAINTAINER=		symka@NetBSD.org
HOMEPAGE=		http://docsis.sourceforge.net/
COMMENT=		Utility for manipulating DOCSIS-compliant cable modems

GNU_CONFIGURE=		YES
USE_TOOLS+=		gm4 bison

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
