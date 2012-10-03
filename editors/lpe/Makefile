# $NetBSD: Makefile,v 1.24 2012/10/03 11:43:36 asau Exp $
#

DISTNAME=	lpe-1.2.6
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.twu.net/users/cdsmith/lpe/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cdsmith.twu.net/professional/opensource/lpe.html
COMMENT=	Small and efficient programmer's editor for UNIX systems

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake msgfmt
GNU_CONFIGURE=		YES

SHLIBTOOL_OVERRIDE=	# empty

# Note: pkglint warns about the following three lines, but they must not
# be changed because this package uses autoconf2.13.
CONFIGURE_ENV=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"
MAKE_ENV=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"
CFLAGS=			-DPREFIX="\"${PREFIX}\""

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	man/lpe.1.cs man/lpe.1.de man/lpe.1.en man/lpe.1.es
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},'

.include "../../devel/libslang/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
