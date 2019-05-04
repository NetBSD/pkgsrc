# $NetBSD: Makefile,v 1.67 2019/05/04 15:32:32 rillig Exp $

DISTNAME=	libiconv-1.14
PKGREVISION=	3
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libiconv/
COMMENT=	Character set conversion library
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pax
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no	# has multiple configure scripts

CONFLICTS=	man-pages-[0-9]*

# Explicitly disable NLS since libiconv is a dependency for gettext-lib
# and we don't want libiconv to pick up any NLS functions from libc
# if they exist.
#
CONFIGURE_ARGS+=	--disable-nls

CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/libiconv

# Explicitly override iconv checks, as GNU libiconv will change its own
# signature based on whether it finds itself already installed somewhere
# which then breaks software (e.g. QT) which assumes the native signature.
#
# Restricted to SunOS for now, but likely will be useful everywhere.
#
CONFIGURE_ENV.SunOS+=	am_cv_func_iconv=yes
CONFIGURE_ENV.SunOS+=	am_cv_proto_iconv_arg1='const'
CONFIGURE_ENV.SunOS+=	am_cv_proto_iconv='extern size_t iconv (iconv_t cd, const char * *inbuf, size_t *inbytesleft, char * *outbuf, size_t *outbytesleft);'

TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/libiconv
REQD_FILES=		${EGDIR}/charset.alias ${PREFIX}/lib/charset.alias

MAKE_ENV+=		PAX=${PAX:Q}

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
