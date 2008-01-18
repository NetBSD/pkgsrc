# $NetBSD: Makefile,v 1.40 2008/01/18 05:14:33 tnn Exp $

DISTNAME=	gnustep-base-1.14.1
PKGREVISION=	1
CATEGORIES=	devel gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	GNUstep foundation classes

USE_LANGUAGES=	objc

#LICENSE=		gnu-gplv3

PTHREAD_LIBS=		-lpthread

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}
MAKE_FILE=		GNUmakefile
MAKE_JOBS_SAFE=		no

SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure base.make.in
SUBST_SED.pthread=	-e 's|@PTHREAD_LIBS@|${PTHREAD_LIBS}|g'

pre-configure:
	sed 's|@PREFIX@|${PREFIX}|g' <${FILESDIR}/openapp >${WRKDIR}/openapp

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/openapp ${PREFIX}/bin

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
.include "../../mk/bsd.pkg.mk"
