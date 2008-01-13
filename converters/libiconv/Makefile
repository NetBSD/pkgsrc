# $NetBSD: Makefile,v 1.53 2008/01/13 09:30:57 joerg Exp $

DISTNAME=	libiconv-1.12
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libiconv/
COMMENT=	Character set conversion library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#LICENSE=		gnu-gplv3 gnu-lgplv2

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


.include "options.mk"

.if ${OPSYS} == "SunOS" || ${OPSYS} == "Linux" || ${OPSYS} == "OSF1"
PLIST_SUBST+=		PRELOADABLE_LIBICONV=""
.else
PLIST_SUBST+=		PRELOADABLE_LIBICONV="@comment "
.endif

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
