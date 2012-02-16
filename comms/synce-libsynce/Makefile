# $NetBSD: Makefile,v 1.5 2012/02/16 17:52:07 hans Exp $
#

DISTNAME=		synce-libsynce-0.9.1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://synce.sourceforge.net/
COMMENT=		Library to support communication with WinCE devices

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
