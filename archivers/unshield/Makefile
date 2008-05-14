# $NetBSD: Makefile,v 1.3 2008/05/14 11:56:26 jmcneill Exp $
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
