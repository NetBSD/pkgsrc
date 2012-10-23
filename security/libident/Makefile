# $NetBSD: Makefile,v 1.22 2012/10/23 18:16:33 asau Exp $
#

VERSION=	0.32
DISTNAME=	libident-${VERSION}
CATEGORIES=	security devel net
MASTER_SITES=	http://www.remlab.net/files/libident/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.remlab.net/libident/
COMMENT=	Small library to interface to the ident protocol server (rfc1413)

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

# Need to specify shlib version for continuousness since old 0.2x version
SUBST_CLASSES+=		libver
SUBST_STAGE.libver=	pre-configure
SUBST_FILES.libver=	Makefile.in
SUBST_SED.libver=	-e "s/^\\(libident_la_LDFLAGS[	 ]*=\\).*/\\1 -version-info ${VERSION:S/./:/}/"

.include "../../mk/bsd.pkg.mk"
