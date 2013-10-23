# $NetBSD: Makefile,v 1.6 2013/10/23 18:22:44 adam Exp $

DISTNAME=	unshield-0.6
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=synce/}

MAINTAINER=	martin@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/synce/
COMMENT=	Extract InstallShield .CAB files
LICENSE=	mit

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libunshield.pc.in

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
