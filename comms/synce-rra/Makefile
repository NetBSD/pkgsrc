# $NetBSD: Makefile,v 1.2 2005/10/13 18:40:21 wiz Exp $
#

DISTNAME=		synce-rra-0.9.1
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

PATCHFILES=		rra-fixes-after-V0_9_1.diff
PATCH_SITES=		http://synce.sourceforge.net/tmp/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Remote Replication Agent Connection protocol library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../comms/synce-librapi2/buildlink3.mk"
.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libmimedir/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
