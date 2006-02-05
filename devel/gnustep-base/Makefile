# $NetBSD: Makefile,v 1.30 2006/02/05 23:08:43 joerg Exp $

DISTNAME=	gnustep-base-1.11.2
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep foundation classes

PTHREAD_LIBS=		-lpthread

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure base.make.in
SUBST_SED.pthread=	-e 's|@PTHREAD_LIBS@|${PTHREAD_LIBS}|g'

pre-configure:
	${SED} 's|@PREFIX@|${PREFIX}|g' <${FILESDIR}/openapp >${WRKDIR}/openapp

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/openapp ${PREFIX}/bin

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc-3*) || !exists(/usr/include/objc/objc.h)
.include "../../devel/gnustep-objc/buildlink3.mk"
.endif

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/ffcall/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/gnustep-make/gnustep.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
