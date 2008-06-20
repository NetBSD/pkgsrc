# $NetBSD: Makefile,v 1.4 2008/06/20 01:09:09 joerg Exp $
#

DISTNAME=		synce-dccm-0.9.1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Listener daemon for connections from WinCE devices

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
