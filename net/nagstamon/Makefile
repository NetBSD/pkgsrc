# $NetBSD: Makefile,v 1.20 2012/10/02 17:11:48 tron Exp $
#

VERSION=	0.9.9
DISTNAME=	nagstamon_${VERSION}
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	3
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagstamon/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://nagstamon.ifw-dresden.de/
COMMENT=	Nagios status monitor which takes place in systray or on desktop
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		# none
PYDISTUTILSPKG=		yes

WRKSRC=			${WRKDIR}/Nagstamon

INSTALLATION_DIRS+=	${PKGMANDIR}/man1
REPLACE_PYTHON=		${WRKSRC}/*.py
REPLACE_PYTHON+=	${WRKSRC}/Nagstamon/Server/Multisite.py

DEPENDS+=	${PYPKGPREFIX}-lxml>=2.2.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-libxslt>=1.1.24:../../textproc/py-libxslt
DEPENDS+=	sox>=14.0.1:../../audio/sox

SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_SED.mandir=	-e s,@PKGMANDIR@,${PKGMANDIR},g
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
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
