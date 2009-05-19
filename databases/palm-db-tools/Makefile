# $NetBSD: Makefile,v 1.5 2009/05/19 08:59:07 wiz Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/./_/g}
PKGNAME=	palm-db-tools-0.3.6
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=palm-db-tools/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/palm-db-tools/
COMMENT=	Conversion utilities for PalmOS flat-file database programs
#LICENSE=	GPL

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/palm-db-tools
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes

# The default of -Werror is a bit optimistic.  This code also causes
# problems attempting to link C++ code with "cc", but using "libtool"
# fixes this.
CONFIGURE_ARGS=	--disable-warnings --enable-libtool

INSTALLATION_DIRS=	share/doc/palm-db-tools
INSTALL_MAKE_FLAGS=	prefix=${DESTDIR}${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/manual.* ${DESTDIR}${PREFIX}/share/doc/palm-db-tools

.include "../../mk/bsd.pkg.mk"
