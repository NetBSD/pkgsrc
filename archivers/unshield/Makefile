# $NetBSD: Makefile,v 1.5 2012/09/11 19:47:02 asau Exp $
#

DISTNAME=		unshield-0.5.1
CATEGORIES=		archivers
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=		martin@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/synce/
COMMENT=		Extract InstallShield .CAB files

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	libunshield.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
