# $NetBSD: Makefile,v 1.52 2012/09/15 10:04:04 obache Exp $
#

DISTNAME=	shared-mime-info-1.0
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://people.freedesktop.org/~hadess/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/shared-mime-info
COMMENT=	Core database of common types
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LANGUAGES+=		c99
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config xgettext
MAKE_JOBS_SAFE=		no

CONFIGURE_ARGS+=	--disable-update-mimedb

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

FILES_SUBST+=		MIMEDB_PATH="${PREFIX}/share/mime"
FILES_SUBST+=		UPDATE_MIMEDB="${PREFIX}/bin/update-mime-database"

PRINT_PLIST_AWK+=	/^share\/mime\/packages/ { print; next; }
PRINT_PLIST_AWK+=	/^share\/mime/ { next; }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
