# $NetBSD: Makefile,v 1.13 2002/09/01 20:24:17 tron Exp $
#

DISTNAME=		libiconv-1.8
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/libiconv/
COMMENT=		character set conversion library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libcharset/libtool

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
PLIST_SUBST+=		SUNOS=
.else
PLIST_SUBST+=		SUNOS="@comment "
.endif

# remove any existing charset.alias; if it already exists, libiconv does
# not overwrite it, and older versions of libiconv wrote incorrect
# charset.alias files, which were not removed during deinstall since
# other packages touched them.
pre-install:
	${RM} -f ${PREFIX}/lib/charset.alias

test: build
	cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_PROGRAM} check |& tee ${WRKDIR}/check.log

.include "../../mk/bsd.pkg.mk"
