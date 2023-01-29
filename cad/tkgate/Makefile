# $NetBSD: Makefile,v 1.37 2023/01/29 21:15:36 ryoon Exp $
#

DISTNAME=	tkgate-1.8.7
PKGREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.tkgate.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tkgate.org/
LICENSE=	gnu-gpl-v2
COMMENT=	Tcl/Tk based digital circuit editor and simulator

BUILD_DEPENDS+=		libiconv-[0-9]*:../../converters/libiconv

USE_IMAKE=		yes
USE_TOOLS+=		gm4 bison

TKGATE_SITENAME=	Earth

CONFIGURE_ENV+=		BUILDLINK_LDFLAGS=${BUILDLINK_LDFLAGS:Q}
CONFIGURE_ENV+=		LOCALBASE=${PREFIX}

SUBST_CLASSES+=		tkgate
SUBST_MESSAGE.tkgate=	Fixing paths in configuration files.
SUBST_STAGE.tkgate=	pre-configure
SUBST_FILES.tkgate=	config.h
SUBST_VARS.tkgate=	LOCALBASE PKGMANDIR PREFIX X11BASE

do-configure:
	${ECHO} "${TKGATE_SITENAME}" > ${WRKSRC}/sitename.txt
	( cd ${WRKSRC} && ${CONFIGURE_ENV} ./configure )

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
