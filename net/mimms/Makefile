# $NetBSD: Makefile,v 1.19 2023/08/14 05:25:02 wiz Exp $

DISTNAME=	mimms-3.2.1
PKGREVISION=	5
CATEGORIES=	net multimedia
MASTER_SITES=	https://download.savannah.gnu.org/releases/mimms/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://savannah.nongnu.org/projects/mimms/
COMMENT=	MMS (e.g. mms://) stream downloader
LICENSE=	gnu-gpl-v3

# default is at lang/python/egg.mk, but
# drop the third digit from DISTNAME. Is it too tricky ?
EGG_NAME?=	${DISTNAME:C/-([^0-9])/_\1/gC/([0-9])\.([0-9])\.([0-9])/\1.\2/}

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 3.2

SUBST_CLASSES+=		man
SUBST_FILES.man+=	setup.py
SUBST_SED.man+=		-e 's,share/man,${PKGMANDIR},'
SUBST_STAGE.man=	post-build
SUBST_MESSAGE.man=	Fixing installation path for man pages.

.include "../../lang/python/egg.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
