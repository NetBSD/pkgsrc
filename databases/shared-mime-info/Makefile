# $NetBSD: Makefile,v 1.14 2006/01/24 07:32:00 wiz Exp $
#

DISTNAME=	shared-mime-info-0.16
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://freedesktop.org/~jrb/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/shared-mime-info
COMMENT=	Core database of common types

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--disable-update-mimedb

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

FILES_SUBST+=		MIMEDB_PATH="${PREFIX}/share/mime"
FILES_SUBST+=		UPDATE_MIMEDB="${PREFIX}/bin/update-mime-database"

PRINT_PLIST_AWK+=	/^share\/mime\/packages/ { print; next; }
PRINT_PLIST_AWK+=	/^share\/mime/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/mime\/packages$$/ { print; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/mime/ { next; }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
