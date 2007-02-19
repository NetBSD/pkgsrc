# $NetBSD: Makefile,v 1.2 2007/02/19 21:57:51 dsainty Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/./_/g}
PKGNAME=	palm-db-tools-0.3.6
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=palm-db-tools/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/palm-db-tools/
COMMENT=	Conversion utilities for PalmOS flat-file database programs

#LICENSE=	GPL

WRKSRC=		${WRKDIR}/palm-db-tools
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

# The default of -Werror is a bit optimistic.  This code also causes
# problems attempting to link C++ code with "cc", but using "libtool"
# fixes this.
CONFIGURE_ARGS=	--disable-warnings --enable-libtool

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/docs/manual.* ${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
