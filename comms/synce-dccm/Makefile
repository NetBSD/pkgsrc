# $NetBSD: Makefile,v 1.2 2005/10/13 15:27:39 wiz Exp $
#

DISTNAME=		synce-dccm-0.9.1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Listener daemon for connections from WinCE devices

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
