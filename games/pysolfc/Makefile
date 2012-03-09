# $NetBSD: Makefile,v 1.11 2012/03/09 12:34:08 wiz Exp $

DISTNAME=	PySolFC-1.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	7
CATEGORIES=	games python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pysolfc/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pysolfc.sourceforge.net/
COMMENT=	Over 1000 solitaire games
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

REPLACE_PYTHON+= \
	data/themes/clearlooks/create_imgs.py \
	pysollib/games/siebenbisas.py

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-patch
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		pysollib/settings.py
SUBST_SED.fix-paths=		-e s,@DATADIR@,${PREFIX}/share/PySolFC/,

INSTALLATION_DIRS+=	${PKGMANDIR}/man6

post-install:
	${INSTALL_MAN} ${WRKSRC}/docs/pysol.6 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/pysol.py.6

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
