# $NetBSD: Makefile,v 1.13 2026/08/03 13:12:23 wiz Exp $

DISTNAME=		synce-rra-0.9.1
PKGREVISION=		2
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

PATCHFILES=		rra-fixes-after-V0_9_1.diff
PATCH_SITES=		http://synce.sourceforge.net/tmp/
PATCH_DIST_STRIP=	-p0

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://synce.sourceforge.net/
COMMENT=		Remote Replication Agent Connection protocol library

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../comms/synce-librapi2/buildlink3.mk"
.include "../../comms/synce-libsynce/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libmimedir/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
