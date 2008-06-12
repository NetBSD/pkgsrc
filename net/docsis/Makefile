# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:39 joerg Exp $
#

DISTNAME=		docsis-0.9.4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=docsis/}

MAINTAINER=		symka@NetBSD.org
HOMEPAGE=		http://docsis.sourceforge.net/
COMMENT=		Utility for manipulating DOCSIS-compliant cable modems

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		bison>=1.25:../../devel/bison

GNU_CONFIGURE=		YES
USE_TOOLS+=		gm4

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
