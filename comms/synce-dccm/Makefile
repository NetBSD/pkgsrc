# $NetBSD: Makefile,v 1.1.1.1 2005/10/13 15:05:16 wiz Exp $
#

DISTNAME=		synce-dccm-0.9.1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		SynCE communication application

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
