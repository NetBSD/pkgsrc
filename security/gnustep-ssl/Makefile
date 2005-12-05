# $NetBSD: Makefile,v 1.10 2005/12/05 20:50:56 rillig Exp $
#

DISTNAME=		gnustep-base-1.10.1
PKGNAME=		${DISTNAME:S/base/ssl/}
CATEGORIES=		security gnustep
MASTER_SITES=		${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnustep.org/
COMMENT=		GNUstep SSL bundle

BUILDLINK_DEPENDS.gnustep-base+=	gnustep-base>1.10.1

PTHREAD_LIBS=		-lpthread

BUILD_DIRS=		SSL
MAKEFILE=		GNUmakefile
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM=${INSTALL_SCRIPT:Q}

SUBST_CLASSES+=		gsssl
SUBST_STAGE.gsssl=	pre-configure
SUBST_FILES.gsssl=	SSL/configure base.make.in
SUBST_SED.gsssl=	-e 's|@PTHREAD_LIBS@|${PTHREAD_LIBS}|g'

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

.include "../../mk/bsd.pkg.mk"
