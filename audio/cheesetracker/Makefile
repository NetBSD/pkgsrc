# $NetBSD: Makefile,v 1.17 2003/05/02 11:53:38 wiz Exp $
#

DISTNAME=		cheesetracker-0.5.5
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://www.reduz.com.ar/cheesetracker/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.reduz.com.ar/cheesetracker/
COMMENT=		impulse tracker clone

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CXXFLAGS="${CXXFLAGS}"
CXXFLAGS+=		-O

AUTOMAKE_REQD=		1.4
PTHREAD_OPTS+=		require

pre-configure:
	${RM} -f ${WRKSRC}/install-sh
	${RM} -f ${WRKSRC}/mkinstalldirs
	${RM} -f ${WRKSRC}/missing
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing

.include "../../mk/automake.mk"
.include "../../lang/gcc/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
