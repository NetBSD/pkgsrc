# $NetBSD: Makefile,v 1.10 2003/12/05 09:16:33 adam Exp $
#

DISTNAME=	gnustep-make-1.8.0
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/core/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep makefile package

USE_GMAKE=		YES
USE_X11=		YES
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
GNUSTEP_HOST_CPU=	${MACHINE_GNU_ARCH:S/i386/ix86/}
CONFIGURE_ARGS+=	--enable-flattened
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"

post-patch:
	${CP} ${WRKSRC}/target.make ${WRKSRC}/target.make.bak
	${SED}  -e 's;/usr/pkg;${LOCALBASE};g' \
		-e 's;@object_fmt@;${LOWER_OPSYS}-${OBJECT_FMT};g' \
		${WRKSRC}/target.make.bak > ${WRKSRC}/target.make

.include "../../mk/bsd.pkg.mk"
