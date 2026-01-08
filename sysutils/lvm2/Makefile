# $NetBSD: Makefile,v 1.3 2026/01/08 07:48:30 wiz Exp $

DISTNAME=	LVM2.2.02.98
PKGNAME=	${DISTNAME:S/LVM2./lvm2-/}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://sources.redhat.com/pub/lvm2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceware.org/lvm2/
COMMENT=	Linux userspace toolset for volume management facilities
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

ONLY_FOR_PLATFORM=	Linux-*-*

PKGCONFIG_OVERRIDE+=	daemons/dmeventd/libdevmapper-event.pc.in
PKGCONFIG_OVERRIDE+=	libdm/libdevmapper.pc.in
PKGCONFIG_OVERRIDE+=	liblvm/liblvm2app.pc.in

.include "../../mk/bsd.pkg.mk"
