# $NetBSD: Makefile,v 1.11 2003/12/05 09:55:46 adam Exp $
#

DISTNAME=		gnustep-base-1.8.0
CATEGORIES=		devel gnustep
MASTER_SITES=		ftp://ftp.gnustep.org/pub/gnustep/core/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnustep.org/
COMMENT=		GNUstep foundation classes

PTHREAD_LIBS=		-lpthread

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
MAKEFILE=		GNUmakefile
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"

pre-configure:
	${SED} 's|@PREFIX@|${PREFIX}|g' <${FILESDIR}/openapp >${WRKDIR}/openapp
.for pfile in configure base.make.in
	${CP} ${WRKSRC}/${pfile} ${WRKSRC}/${pfile}.tmpl
	${SED} 's|@PTHREAD_LIBS@|${PTHREAD_LIBS}|g'			\
		<${WRKSRC}/${pfile}.tmpl >${WRKSRC}/${pfile}
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/openapp ${PREFIX}/bin

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/ffcall/buildlink2.mk"
.include "../../devel/gmp/buildlink2.mk"
.include "../../devel/gnustep-objc/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

.include "../../mk/bsd.pkg.mk"
