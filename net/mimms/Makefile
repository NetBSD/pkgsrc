# $NetBSD: Makefile,v 1.3 2014/05/09 07:37:14 wiz Exp $

DISTNAME=	mimms-3.2
CATEGORIES=	net multimedia
MASTER_SITES=	http://download.savannah.gnu.org/releases/mimms/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/mimms/
COMMENT=	MMS (e.g. mms://) stream downloader
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 3.2

SUBST_CLASSES+=		man
SUBST_FILES.man+=	setup.py
SUBST_SED.man+=		-e 's,share/man,${PKGMANDIR},'
SUBST_STAGE.man=	post-build
SUBST_MESSAGE.man=	Fixing installation path for man pages.

.include "../../lang/python/distutils.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
