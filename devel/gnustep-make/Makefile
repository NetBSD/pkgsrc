# $NetBSD: Makefile,v 1.4 2002/09/29 23:45:52 rh Exp $
#

DISTNAME=		gnustep-make-1.5.0
PKGREVISION=		3
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
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"

PLIST_SUBST+=	GNUSTEP_HOST_CPU=${MACHINE_GNU_ARCH:S/i386/ix86/}
PLIST_SUBST+=	APPEND_ELF=${APPEND_ELF}

post-extract:
	${CP} ${WRKSRC}/target.make ${WRKSRC}/target.make.orig \
		&& ${SED} 's!/usr/pkg!${LOCALBASE}!g' \
			${WRKSRC}/target.make.orig > ${WRKSRC}/target.make

.include "../../mk/bsd.pkg.mk"
