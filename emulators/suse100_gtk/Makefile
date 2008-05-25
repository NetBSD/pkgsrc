# $NetBSD: Makefile,v 1.5 2008/05/25 14:45:17 tron Exp $

DISTNAME=	suse_gtk-${SUSE_VERSION}
PKGREVISION=	2
CATEGORIES=	emulators
DISTFILES=	glib-1.2.10-595.${SUSE_ARCH}.rpm			\
		gtk-1.2.10-888.${SUSE_ARCH}.rpm

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Linux compatibility package for GTK+-1.x

EMUL_MODULES.linux=	x11

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
