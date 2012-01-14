# $NetBSD: Makefile,v 1.16 2012/01/14 00:51:36 hans Exp $
#

DISTNAME=		docsis-0.9.4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docsis/}

MAINTAINER=		symka@NetBSD.org
HOMEPAGE=		http://docsis.sourceforge.net/
COMMENT=		Utility for manipulating DOCSIS-compliant cable modems

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		gm4 bison

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
