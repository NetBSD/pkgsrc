# $NetBSD: Makefile,v 1.8 2004/01/25 03:08:46 grant Exp $
#

DISTNAME=	tkgate-1.6i
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://gadoid.ices.cmu.edu/pub/tkgate/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www-2.cs.cmu.edu/~hansen/tkgate/
COMMENT=	Tcl/Tk based digital circuit editor and simulator

BUILD_DEPENDS+=		bison>=1.35:../../devel/bison
BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv

USE_BUILDLINK2=		yes
USE_IMAKE=		yes
USE_GNU_TOOLS+=		m4

TKGATE_SITENAME=	Earth

CONFIG_SUBST=		PREFIX="${PREFIX}"
CONFIG_SUBST+=		LOCALBASE="${LOCALBASE}"
CONFIG_SUBST+=		X11BASE="${X11BASE}"
CONFIG_SUBST_SED=	${CONFIG_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

post-extract:
	( cd ${WRKSRC} && ${MV} config.h config.h.in )

do-configure:
	${SED} ${CONFIG_SUBST_SED} ${WRKSRC}/config.h.in > ${WRKSRC}/config.h
	${ECHO} "${TKGATE_SITENAME}" > ${WRKSRC}/sitename.txt
	( cd ${WRKSRC} && ${CONFIGURE_ENV} ./configure )

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
