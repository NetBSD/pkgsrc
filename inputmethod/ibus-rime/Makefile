# $NetBSD: Makefile,v 1.12 2018/08/16 18:54:56 adam Exp $

DISTNAME=	ibus-rime-1.0
PKGREVISION=	9
CATEGORIES=	inputmethod chinese
MASTER_SITES=	http://rimeime.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rime.im/
COMMENT=	Rime Input Method Engine for Linux/IBus
LICENSE=	gnu-gpl-v3

DEPENDS+=	brise>=0.30:../../inputmethod/brise

WRKSRC=		${WRKDIR}/ibus-rime
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

INSTALLATION_DIRS+=	share/ibus/component lib/ibus-rime share/ibus-rime/icons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ibus-engine-rime ${DESTDIR}${PREFIX}/lib/ibus-rime/
	${INSTALL_DATA} ${WRKSRC}/rime.xml ${DESTDIR}${PREFIX}/share/ibus/component/
	${INSTALL_DATA} ${WRKSRC}/rime.png ${DESTDIR}${PREFIX}/share/ibus-rime/icons/

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	rime.xml
SUBST_SED.prefix=	-e 's,/usr/,${PREFIX}/,g'

.include "../../inputmethod/librime/buildlink3.mk"
.include "../../inputmethod/ibus/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
