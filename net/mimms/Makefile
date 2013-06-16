# $NetBSD: Makefile,v 1.1 2013/06/16 21:21:15 wiz Exp $

DISTNAME=	mimms-3.2
CATEGORIES=	net multimedia
MASTER_SITES=	http://download.savannah.gnu.org/releases/mimms/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/mimms/
COMMENT=	MMS (e.g. mms://) stream downloader
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

SUBST_CLASSES+=		man
SUBST_FILES.man+=	setup.py
SUBST_SED.man+=		-e 's,share/man,${PKGMANDIR},'
SUBST_STAGE.man=	post-build
SUBST_MESSAGE.man=	Fixing installation path for man pages.

.include "../../lang/python/distutils.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
