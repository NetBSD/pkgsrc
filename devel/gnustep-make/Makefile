# $NetBSD: Makefile,v 1.13 2004/03/31 19:20:26 minskim Exp $
#

DISTNAME=	gnustep-make-1.8.0
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/core/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_X11=		YES
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
GNUSTEP_HOST_CPU=	${MACHINE_GNU_ARCH:S/i386/ix86/}
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"

post-patch:
	${CP} ${WRKSRC}/target.make ${WRKSRC}/target.make.bak
	${SED}  -e 's;/usr/pkg;${LOCALBASE};g' \
		-e 's;@object_fmt@;${LOWER_OPSYS}-${OBJECT_FMT};g' \
		${WRKSRC}/target.make.bak > ${WRKSRC}/target.make

post-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/share/GNUstep/Local/Applications
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Bundles
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Headers
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/Libraries

.include "../../mk/bsd.pkg.mk"
