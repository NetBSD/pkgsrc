# $NetBSD: Makefile,v 1.11 2002/08/08 16:17:05 jlam Exp $
#

DISTNAME=		cheesetracker-0.5.5
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.reduz.com.ar/cheesetracker/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.reduz.com.ar/cheesetracker/
COMMENT=		impulse tracker clone

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
DEPENDS+=		gtk-->=1.2:../../x11/gtk--

GCC_VERSION!=           gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
# "egcs" cannot be used, as this package tickles c++ compiler bugs
.  include "../../lang/gcc/Makefile.gcc"
.endif

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

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
