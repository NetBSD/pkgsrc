# $NetBSD: Makefile,v 1.1.1.1 2002/09/27 10:58:42 rh Exp $
#

DISTNAME=		gnustep-base-1.5.0
CATEGORIES=		devel gnustep
MASTER_SITES=		ftp://ftp.gnustep.org/pub/gnustep/core/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnustep.org/
COMMENT=		GNUstep foundation classes

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"
LIBS+=			-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -lpthread

.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/ffcall/buildlink2.mk"
.include "../../devel/gnustep-objc/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
