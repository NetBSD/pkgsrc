# $NetBSD: Makefile,v 1.24 2006/09/03 10:19:01 wiz Exp $
#

DISTNAME=	shared-mime-info-0.19
CATEGORIES=	databases
MASTER_SITES=	http://freedesktop.org/~hadess/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/shared-mime-info
COMMENT=	Core database of common types

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config

CONFIGURE_ARGS+=	--disable-update-mimedb

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DPREFIX="\"${PREFIX}\""

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=		-c99
.endif

FILES_SUBST+=		MIMEDB_PATH="${PREFIX}/share/mime"
FILES_SUBST+=		UPDATE_MIMEDB="${PREFIX}/bin/update-mime-database"

PRINT_PLIST_AWK+=	/^share\/mime\/packages/ { print; next; }
PRINT_PLIST_AWK+=	/^share\/mime/ { next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/mime\/packages$$/ { print; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/mime/ { next; }

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
