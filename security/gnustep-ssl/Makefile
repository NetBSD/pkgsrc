# $NetBSD: Makefile,v 1.3 2004/10/03 00:18:08 tv Exp $
#

DISTNAME=		gnustep-base-1.10.0
PKGNAME=		${DISTNAME:S/base/ssl/}
PKGREVISION=	1
CATEGORIES=		security gnustep
MASTER_SITES=		ftp://ftp.gnustep.org/pub/gnustep/core/

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnustep.org/
COMMENT=		GNUstep SSL bundle

BUILDLINK_DEPENDS.gnustep-base=	gnustep-base>=1.10.0

CONFLICTS+=	gnustep-base<1.9.1

PTHREAD_LIBS=		-lpthread

CONFIGURE_DIRS=		${WRKDIR}/${DISTNAME}
WRKSRC=			${CONFIGURE_DIRS}/SSL
MAKEFILE=		GNUmakefile
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/share/GNUstep
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_SCRIPT}"

pre-configure:
.for pfile in configure ../base.make.in
	${CP} ${WRKSRC}/${pfile} ${WRKSRC}/${pfile}.tmpl
	${SED} 's|@PTHREAD_LIBS@|${PTHREAD_LIBS}|g'			\
		<${WRKSRC}/${pfile}.tmpl >${WRKSRC}/${pfile}
.endfor

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && (${PTHREAD_TYPE} == "pth")
PTHREAD_LIBS+=		-lpth
.endif

.include "../../mk/bsd.pkg.mk"
