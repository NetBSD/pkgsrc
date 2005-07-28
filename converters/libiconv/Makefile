# $NetBSD: Makefile,v 1.35 2005/07/28 15:15:17 adam Exp $

DISTNAME=	libiconv-1.10
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libiconv/
COMMENT=	Character set conversion library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/libiconv
SUPPORT_FILES=		${EGDIR}/charset.alias ${PREFIX}/lib/charset.alias

MAKE_ENV+=		PAX="${PAX}"

# remove any existing charset.alias; if it already exists, libiconv does
# not overwrite it, and older versions of libiconv wrote incorrect
# charset.alias files, which were not removed during deinstall since
# other packages touched them.
pre-install:
	${RM} -f ${PREFIX}/lib/charset.alias

# be sure to install a new charset.alias
post-install:
	cd ${WRKSRC}/libcharset/lib && ${MAKE} libdir=${EGDIR} \
		install-charset-alias

.include "../../mk/bsd.pkg.mk"
