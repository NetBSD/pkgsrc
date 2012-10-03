# $NetBSD: Makefile,v 1.62 2012/10/03 00:20:11 asau Exp $

DISTNAME=	libiconv-1.14
PKGREVISION=	2
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libiconv/
COMMENT=	Character set conversion library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=	pax
GNU_CONFIGURE=		yes

CONFLICTS=	man-pages-[0-9]*

# Explicitly disable NLS since libiconv is a dependency for gettext-lib
# and we don't want libiconv to pick up any NLS functions from libc
# if they exist.
#
CONFIGURE_ARGS+=	--disable-nls

CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/libiconv

TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/libiconv
REQD_FILES=		${EGDIR}/charset.alias ${PREFIX}/lib/charset.alias

MAKE_ENV+=		PAX=${PAX:Q}
MAKE_JOBS_SAFE=		no		# ENOENT(srclib)

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mmipspro*)
CFLAGS+=		-c99
.endif

# no patch for libiconv-1.14 available yet
#.include "options.mk"

PLIST_VARS+=		preload

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux" || ${OPSYS} == "OSF1"
PLIST.preload=		yes
.endif

# remove any existing charset.alias; if it already exists, libiconv does
# not overwrite it, and older versions of libiconv wrote incorrect
# charset.alias files, which were not removed during deinstall since
# other packages touched them.
pre-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/charset.alias

# be sure to install a new charset.alias
post-install:
	cd ${WRKSRC}/libcharset/lib && \
		${MAKE} libdir=${EGDIR} DESTDIR=${DESTDIR} install-charset-alias

.include "../../mk/bsd.pkg.mk"
