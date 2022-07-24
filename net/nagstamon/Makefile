# $NetBSD: Makefile,v 1.70 2022/07/24 21:15:18 wiz Exp $

VERSION=	1.0.1
DISTNAME=	Nagstamon-${VERSION}
PKGNAME=	${DISTNAME:S/N/n/}
PKGREVISION=	24
CATEGORIES=	net python
MASTER_SITES=	https://nagstamon.ifw-dresden.de/files-nagstamon/stable/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	https://nagstamon.ifw-dresden.de/
COMMENT=	Nagios status monitor which takes place in systray or on desktop
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-libxslt>=1.1.24:../../textproc/py-libxslt
DEPENDS+=	sox>=14.0.1:../../audio/sox

USE_LANGUAGES=		# none

WRKSRC=			${WRKDIR}/Nagstamon

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
REPLACE_PYTHON=		${WRKSRC}/*.py
REPLACE_PYTHON+=	${WRKSRC}/Nagstamon/Server/Multisite.py

PYTHON_VERSIONS_ACCEPTED=	27 # py-libxslt, py-ORBit via py-gnome2, py-gtk2

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_VARS.mandir=	PKGMANDIR
SUBST_FILES.mandir=	setup.py

# Upstream renamed script from nagstamon to nagstamon.py
# Preserve compatibility with previous version of the package
post-install:
	${LN} -s ${DESTDIR}${PREFIX}/bin/nagstamon.py \
		${DESTDIR}${PREFIX}/bin/nagstamon

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
