# $NetBSD: Makefile,v 1.1.1.1 2002/10/29 00:33:46 dmcmahill Exp $
#

DISTNAME=	tkgate-1.6i
CATEGORIES=	cad
MASTER_SITES=	ftp://gadoid.ices.cmu.edu/pub/tkgate/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmmv@hispabsd.org
HOMEPAGE=	http://www-2.cs.cmu.edu/~hansen/tkgate/
COMMENT=	Tcl/Tk based digital circuit editor and simulator

BUILD_DEPENDS+=		bison>=1.35:../../devel/bison

USE_BUILDLINK2=		yes
USE_IMAKE=		yes

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
