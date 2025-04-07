# $NetBSD: Makefile,v 1.24 2025/04/07 15:27:03 nia Exp $
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

CFLAGS.SCO_SV+=		-DFNDELAY=O_NONBLOCK
CFLAGS.UnixWare+=	-DFNDELAY=O_NONBLOCK

# Need to specify shlib version for continuousness since old 0.2x version
SUBST_CLASSES+=		libver
SUBST_STAGE.libver=	pre-configure
SUBST_FILES.libver=	Makefile.in
SUBST_SED.libver=	-e "s/^\\(libident_la_LDFLAGS[	 ]*=\\).*/\\1 -version-info ${VERSION:S/./:/}/"

.include "../../mk/bsd.pkg.mk"
