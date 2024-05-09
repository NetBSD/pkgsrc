# $NetBSD: Makefile,v 1.4 2024/05/09 01:32:35 pho Exp $

DISTNAME=	dbus-1.3.4
PKGREVISION=	1
CATEGORIES=	sysutils
DIST_SUBDIR=	${PKGBASE} # To avoid conflicting with sysutils/dbus

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Client library for the D-Bus IPC system
LICENSE=	apache-2.0

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-lens/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-split/buildlink3.mk"
.include "../../devel/hs-th-lift/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-xml-conduit/buildlink3.mk"
.include "../../textproc/hs-xml-types/buildlink3.mk"
.include "../../mk/haskell.mk"
.include "../../mk/bsd.pkg.mk"
