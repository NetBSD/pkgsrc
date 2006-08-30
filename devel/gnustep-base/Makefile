# $NetBSD: Makefile,v 1.35 2006/08/30 14:55:00 adam Exp $

DISTNAME=	gnustep-base-1.13.0
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep foundation classes

USE_LANGUAGES=	objc

PTHREAD_LIBS=		-lpthread

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX:Q}/libexec/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure base.make.in
SUBST_SED.pthread=	-e 's|@PTHREAD_LIBS@|${PTHREAD_LIBS}|g'

pre-configure:
	sed 's|@PREFIX@|${PREFIX}|g' <${FILESDIR:Q}/openapp >${WRKDIR:Q}/openapp

post-install:
	${INSTALL_SCRIPT} ${WRKDIR:Q}/openapp ${PREFIX:Q}/bin

.include "../../mk/compiler.mk"

.if empty(CC_VERSION:Mgcc-[34]*) || !exists(/usr/include/objc/objc.h)
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
