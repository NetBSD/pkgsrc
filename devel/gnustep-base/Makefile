# $NetBSD: Makefile,v 1.18 2004/10/03 00:13:28 tv Exp $

DISTNAME=	gnustep-base-1.10.0
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/core/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep foundation classes

PTHREAD_LIBS=		-lpthread

USE_BUILDLINK3=		yes
USE_X11=		yes
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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ffcall/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc-3*)
.include "../../devel/gnustep-objc/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

.include "../../devel/gnustep-make/gnustep.mk"
.include "../../mk/bsd.pkg.mk"
