# $NetBSD: Makefile,v 1.3 2006/06/15 13:26:56 wiz Exp $
#

DISTNAME=		synce-librapi2-0.9.1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Utilities/libraries to make RAPI calls on WinCE devices

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
