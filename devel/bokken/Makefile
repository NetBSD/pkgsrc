# $NetBSD: Makefile,v 1.3 2015/11/19 07:46:57 wiz Exp $

DISTNAME=	bokken-1.8
CATEGORIES=	devel
MASTER_SITES=	https://inguma.eu/attachments/download/212/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://bokken.re/
COMMENT=	Open Source Reverse Code Engineering
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-graphviz-[0-9]*:../../graphics/py-graphviz
DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
DEPENDS+=	${PYPKGPREFIX}-gtksourceview-[0-9]*:../../x11/py-gtksourceview
DEPENDS+=	${PYPKGPREFIX}-radare2-[0-9]*:../../devel/py-radare2

USE_TOOLS+=	pax

NO_BUILD=	yes

REPLACE_PYTHON=	bokken.py lib/web/utils.py ui/xdot.py
REPLACE_SH=	bokken

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # py-gtk2

SUBST_CLASSES+=			bin-bokken
SUBST_STAGE.bin-bokken=		post-patch
SUBST_MESSAGE.bin-bokken=	Fixing path to bokken.py
SUBST_FILES.bin-bokken=		bokken
SUBST_SED.bin-bokken=	-e 's,`dirname $$0`,"${PREFIX}/share/bokken",'

SUBST_CLASSES+=			bin-dot
SUBST_STAGE.bin-dot=		post-patch
SUBST_MESSAGE.bin-dot=		Fixing path to dot(1)
SUBST_FILES.bin-dot=		ui/graph.py
SUBST_SED.bin-dot=	-e 's,/usr/bin/dot,${PREFIX}/bin/dot,'

INSTALLATION_DIRS=	bin share/bokken

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/bokken
	${RM} ${DESTDIR}${PREFIX}/share/bokken/.gitignore
	${MV} ${DESTDIR}${PREFIX}/share/bokken/bokken ${DESTDIR}${PREFIX}/bin/bokken

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
