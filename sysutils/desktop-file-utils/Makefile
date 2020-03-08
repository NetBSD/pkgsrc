# $NetBSD: Makefile,v 1.41 2020/03/08 16:51:15 wiz Exp $

DISTNAME=	desktop-file-utils-0.24
PKGREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://freedesktop.org/software/desktop-file-utils/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/desktop-file-utils
COMMENT=	Utilities to manage desktop entries
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	EMACS=no

LDFLAGS.SunOS+=		-lintl

FILES_SUBST+=		APPLICATIONS_PATH="${PREFIX}/share/applications"
FILES_SUBST+=		UPDATE_DESKTOPDB="${PREFIX}/bin/update-desktop-database"

PRINT_PLIST_AWK+=	/^share\/applications\/mimeinfo.cache$$/ \
				{ print "@comment in INSTALL script: " $$0; \
				  next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
