# $NetBSD: Makefile,v 1.22 2003/09/12 19:03:58 recht Exp $
#

DISTNAME=		cheesetracker-0.5.5
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		http://www.reduz.com.ar/cheesetracker/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.reduz.com.ar/cheesetracker/
COMMENT=		Impulse tracker clone

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
.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
