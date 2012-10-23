# $NetBSD: Makefile,v 1.26 2012/10/23 17:18:25 asau Exp $

DISTNAME=	gtk_wicontrol-0.17
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://www.izawa.org/software/gtk_wicontrol/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.izawa.org/software/gtk_wicontrol/
COMMENT=	GTK+-based Wavelan status meter

ONLY_FOR_PLATFORM=	*BSD-*-* DragonFly-*-*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt

INSTALL_MAKE_FLAGS+=	AM_INSTALL_PROGRAM_FLAGS=

SPECIAL_PERMS+=	bin/gtk_wicontrol ${SETUID_ROOT_PERMS}

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
