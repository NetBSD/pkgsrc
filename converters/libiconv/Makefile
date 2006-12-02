# $NetBSD: Makefile,v 1.45 2006/12/02 22:33:00 jschauma Exp $

DISTNAME=	libiconv-1.10
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libiconv/
COMMENT=	Character set conversion library

PATCH_SITES=	http://www2d.biglobe.ne.jp/~msyk/software/libiconv/
PATCHFILES=	libiconv-1.10-ja-1.patch.gz
PATCH_DIST_STRIP=	-p1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

# Explicitly disable NLS since libiconv is a dependency for gettext-lib
# and we don't want libiconv to pick up any NLS functions from libc
# if they exist.
#
CONFIGURE_ARGS+=	--disable-nls

TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/libiconv
REQD_FILES=		${EGDIR}/charset.alias ${PREFIX}/lib/charset.alias

MAKE_ENV+=		PAX=${PAX:Q}

# remove any existing charset.alias; if it already exists, libiconv does
# not overwrite it, and older versions of libiconv wrote incorrect
# charset.alias files, which were not removed during deinstall since
# other packages touched them.
pre-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/charset.alias

# be sure to install a new charset.alias
post-install:
	cd ${WRKSRC}/libcharset/lib && ${MAKE} libdir=${EGDIR} DESTDIR=${DESTDIR:Q} \
		install-charset-alias

.include "../../mk/bsd.pkg.mk"
