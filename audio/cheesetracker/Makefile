# $NetBSD: Makefile,v 1.14 2002/09/29 03:27:57 jlam Exp $
#

DISTNAME=		cheesetracker-0.5.5
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.reduz.com.ar/cheesetracker/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.reduz.com.ar/cheesetracker/
COMMENT=		impulse tracker clone

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="${CXXFLAGS}"
CXXFLAGS+=		-O

PTHREAD_OPTS+=		require

post-extract:
	${RM} -f ${WRKSRC}/install-sh
	${RM} -f ${WRKSRC}/mkinstalldirs
	${CP} ${LOCALBASE}/share/automake/install-sh ${WRKSRC}/install-sh
	${CP} ${LOCALBASE}/share/automake/mkinstalldirs ${WRKSRC}/mkinstalldirs

.include "../../lang/gcc/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
