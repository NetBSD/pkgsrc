# $NetBSD: Makefile,v 1.7 2002/07/16 08:24:15 agc Exp $
#

DISTNAME=		cheesetracker-0.5.5
CATEGORIES=		audio
MASTER_SITES=		http://www.reduz.com.ar/cheesetracker/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.reduz.com.ar/cheesetracker/
COMMENT=		impulse tracker clone

DEPENDS+=		gtk-->=1.2:../../x11/gtk--

GCC_VERSION!=           gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
# "egcs" cannot be used, as this package tickles c++ compiler bugs
.include "../../lang/gcc/Makefile.gcc"
.endif
GNU_CONFIGURE=		yes
# XXX: This package assumes pthread is pth.
#      (glib specifies `USE_PTHREAD=native pth.')
CONFIGURE_ENV=		CXXFLAGS="-O -Dusleep=pth_usleep"
USE_GMAKE=		yes

post-extract:
	${RM} -f ${WRKSRC}/install-sh
	${RM} -f ${WRKSRC}/mkinstalldirs
	${LN} -s ${LOCALBASE}/share/automake/install-sh ${WRKSRC}/install-sh
	${LN} -s ${LOCALBASE}/share/automake/mkinstalldirs ${WRKSRC}/mkinstalldirs

.include "../../mk/bsd.pkg.mk"
