# $NetBSD: Makefile,v 1.6 2003/02/06 10:54:17 dmcmahill Exp $
#

DISTNAME=		gnustep-make-1.5.1
CATEGORIES=		devel gnustep
MASTER_SITES=		ftp://ftp.gnustep.org/pub/gnustep/core/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnustep.org/
COMMENT=		GNUstep makefile package

USE_GMAKE=		YES
USE_X11=		YES
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
GNUSTEP_HOST_CPU=	${MACHINE_GNU_ARCH:S/i386/ix86/}
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"

PLIST_SUBST+=	GNUSTEP_HOST_CPU=${GNUSTEP_HOST_CPU}
PLIST_SUBST+=	APPEND_ELF=${APPEND_ELF}

post-patch:
	${CP} ${WRKSRC}/target.make ${WRKSRC}/target.make.bak && \
		${SED} -e 's;/usr/pkg;${LOCALBASE};g'  -e 's;@object_fmt@;${LOWER_OPSYS}-${OBJECT_FMT};g' \
			${WRKSRC}/target.make.bak > ${WRKSRC}/target.make

post-install:
.for sub in System Local
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/${sub}/Headers/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}
.for dir in Libraries Tools
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/${sub}/${dir}/${GNUSTEP_HOST_CPU}/${LOWER_OPSYS}${APPEND_ELF}/gnu-gnu-gnu
.endfor
.endfor
.for dir in Services PostScript Frameworks Colors Bundles
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Library/${dir}
.endfor
.for dir in Resources Java
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Libraries/${dir}
.endfor
.for dir in User Developer
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Documentation/${dir}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Developer/Palettes
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Applications
	${INSTALL_DATA_DIR} ${PREFIX}/share/GNUstep/Local/Tools/Java

.include "../../mk/bsd.pkg.mk"
