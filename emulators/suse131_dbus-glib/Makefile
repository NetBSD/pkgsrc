# $NetBSD: Makefile,v 1.5 2015/12/29 04:04:28 dholland Exp $

PKGNAME=	suse_dbus-glib-${SUSE_VERSION}
CATEGORIES=	emulators
RPMPKGS+=	dbus-1-glib-0.100.2-2.1.3.${SUSE_ARCH}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for dbus-glib

EMUL_MODULES.linux=	base dbus

.include "../../emulators/suse131_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
