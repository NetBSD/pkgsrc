# $NetBSD: Makefile,v 1.1.1.1 2002/09/27 10:40:16 rh Exp $
#

DISTNAME=		gnustep-make-1.5.0
CATEGORIES=		devel
MASTER_SITES=		ftp://ftp.gnustep.org/pub/gnustep/core/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnustep.org/
COMMENT=		GNUstep makefile package

USE_GMAKE=		YES
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"

PLIST_SUBST+=	GNUSTEP_HOST_CPU=${MACHINE_GNU_ARCH:S/i386/ix86/}
PLIST_SUBST+=	APPEND_ELF=${APPEND_ELF}

.include "../../mk/bsd.pkg.mk"
