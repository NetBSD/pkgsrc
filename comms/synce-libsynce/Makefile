# $NetBSD: Makefile,v 1.6 2012/10/03 11:24:44 asau Exp $
#

DISTNAME=		synce-libsynce-0.9.1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Library to support communication with WinCE devices

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
