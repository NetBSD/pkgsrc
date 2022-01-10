# $NetBSD: Makefile,v 1.40 2022/01/10 08:11:43 wiz Exp $

PKGVERSION=	20211216
PKGNAME=	chirp-${PKGVERSION}
DISTNAME=	chirp-daily-${PKGVERSION_NOREV}
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	https://trac.chirp.danplanet.com/chirp_daily/daily-${PKGVERSION_NOREV}/
# Chirp does not have what would normally called releasees.  They have
# "daily builds" which are like releases except that:
#   they are called chirp-daily instead of chirp
#   they have YYYYMMDD version numbers
#   they don't have the usual release testing
# Upstream says
#    they will not go back to regular version numbers
#    the preferred name is chirp, not chirp-daily
# via
#   https://chirp.danplanet.com/issues/8067
#   https://chirp.danplanet.com/news/15

MAINTAINER=	dbj@NetBSD.org
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://chirp.danplanet.com/projects/chirp/wiki/Home
COMMENT=	Tool for programming Amateur Radio HTs
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	#none
REPLACE_PYTHON=	*.py chirp/*.py chirp/ui/*.py

DEPENDS+=	${PYPKGPREFIX}-serial>=2.7:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-future>=0.18.0:../../devel/py-future

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=			fix-manpaths
SUBST_STAGE.fix-manpaths=	pre-configure
SUBST_MESSAGE.fix-manpaths=	Fixing man paths
SUBST_FILES.fix-manpaths=	setup.py
SUBST_SED.fix-manpaths=		-e 's,share/man/man1,${PKGMANDIR}/man1,g'

SUBST_CLASSES+=			fix-sharepaths
SUBST_STAGE.fix-sharepaths=	pre-configure
SUBST_MESSAGE.fix-sharepaths=	Fixing /usr/share paths
SUBST_FILES.fix-sharepaths=	chirp/platform.py
SUBST_SED.fix-sharepaths=	-e 's,/usr/share,${PREFIX}/share,g'

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/py-libxml2/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
