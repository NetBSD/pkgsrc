# $NetBSD: Makefile,v 1.17 2003/07/12 13:13:46 dillo Exp $
#

DISTNAME=		libiconv-1.8
PKGREVISION=		1
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=libiconv/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/libiconv/
COMMENT=		character set conversion library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libcharset/libtool

TEST_TARGET=		check

# remove any existing charset.alias; if it already exists, libiconv does
# not overwrite it, and older versions of libiconv wrote incorrect
# charset.alias files, which were not removed during deinstall since
# other packages touched them.
pre-install:
	${RM} -f ${PREFIX}/lib/charset.alias

# be sure to install a new charset.alias
post-install:
	cd ${WRKSRC}/libcharset/lib && ${MAKE} install-lib

.include "../../mk/bsd.pkg.mk"
