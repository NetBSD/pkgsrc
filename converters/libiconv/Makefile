# $NetBSD: Makefile,v 1.25 2004/04/02 19:08:37 jschauma Exp $
#

DISTNAME=		libiconv-1.9.1
PKGREVISION=		1
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libiconv/
COMMENT=		Character set conversion library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

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
