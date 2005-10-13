# $NetBSD: Makefile,v 1.1.1.1 2005/10/13 16:57:41 wiz Exp $
#

DISTNAME=		synce-rra-0.9.1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Remote Replication Agent Connection protocol library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../comms/synce-librapi2/buildlink3.mk"
.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libmimedir/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
