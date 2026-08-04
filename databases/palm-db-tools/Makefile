# $NetBSD: Makefile,v 1.10 2026/08/04 20:28:49 wiz Exp $
#

DISTNAME=	${PKGNAME_NOREV:S/./_/g}
PKGNAME=	palm-db-tools-0.3.6
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=palm-db-tools/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/palm-db-tools/
COMMENT=	Conversion utilities for PalmOS flat-file database programs
LICENSE=	gnu-gpl-v2

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

# Case-insensitive filesystems confuse make install without this.
post-extract:
	cd ${WRKSRC} && mv INSTALL INSTALL.txt

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/manual.* ${DESTDIR}${PREFIX}/share/doc/palm-db-tools

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
