# $NetBSD: Makefile,v 1.43 2024/05/16 06:15:33 wiz Exp $

DISTNAME=	e_dbus-1.7.10
PKGNAME=	${DISTNAME:S/e_dbus/edbus/}
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.enlightenment.org/
COMMENT=	Convenience wrappers around dbus to ease integrating dbus with E17
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	ehal.pc.in edbus.pc.in enm.pc.in enotify.pc.in

.include "../../devel/ecore/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/efreet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
