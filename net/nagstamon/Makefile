# $NetBSD: Makefile,v 1.8 2011/11/01 06:02:21 sbd Exp $
#

VERSION=	0.9.2
DISTNAME=	nagstamon_${VERSION}
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	7
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagstamon/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://nagstamon.sf.net/
COMMENT=	Nagios status monitor which takes place in systray or on desktop
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# none
PYDISTUTILSPKG=		yes

# Upstream's aware of this
SUBST_CLASSES+=		typo
SUBST_STAGE.typo=	post-extract
SUBST_FILES.typo=	${WRKSRC}/Nagstamon/nagstamonGUI.py
SUBST_SED.typo=		-e 's|\#!/usr/bin/py\ .*|\#!/usr/bin/python|'
SUBST_MESSAGE.typo=	Fixing interpreter typo.

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
REPLACE_PYTHON=		${WRKSRC}/Nagstamon/*.py
REPLACE_PYTHON+=	${WRKSRC}/Nagstamon/nagstamon

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-libxslt>=1.1.24:../../textproc/py-libxslt
DEPENDS+=	sox>=14.0.1:../../audio/sox

post-install:
	${INSTALL_MAN} files/nagstamon.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/py-gnome2-extras/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
