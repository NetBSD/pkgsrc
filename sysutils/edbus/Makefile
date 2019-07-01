# $NetBSD: Makefile,v 1.23 2019/07/01 04:07:51 ryoon Exp $

DISTNAME=	e_dbus-1.7.7
PKGNAME=	edbus-1.7.7
PKGREVISION=	13
CATEGORIES=	sysutils
MASTER_SITES=	http://download.enlightenment.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
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
