# $NetBSD: Makefile,v 1.9 2025/11/17 11:00:28 wiz Exp $
#

DISTNAME=		synce-libsynce-0.9.1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://synce.sourceforge.net/
COMMENT=		Library to support communication with WinCE devices

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
