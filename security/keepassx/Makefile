# $NetBSD: Makefile,v 1.2 2009/07/17 18:00:24 adrianp Exp $
#

DISTNAME=	KeePassX-0.2.2
PKGNAME=	${DISTNAME:S/KeePassX/keepassx/}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=keepassx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keepassx.sourceforge.net/
COMMENT=	Password manager or safe

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

QMAKE=			${QTDIR}/bin/qmake
CONFIGURE_ARGS+=	QMAKE=${QMAKE:Q} PREFIX=${PREFIX:Q}
MAKE_ENV+=		QTDIR=${QTDIR} PREFIX=${PREFIX}

BUILDLINK_DEPMETHOD.qt3-tools=	build

do-configure:
	cd ${WRKSRC} && \
		${QMAKE} -o Makefile ${CONFIGURE_ARGS} keepass.pro

pre-install:
	${CP} ${WRKSRC}/bin/keepass ${WRKSRC}/src

post-install:
	${CHMOD} ${SHAREMODE} ${PREFIX}/share/keepass/icons/*.png

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
