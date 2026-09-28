# $NetBSD: Makefile,v 1.79 2026/09/28 22:14:15 gdt Exp $

VERSION=	20260904
DISTNAME=	chirp-${VERSION}
PKGREVISION=	1
CATEGORIES=	ham
# As of sometime after 20251128 and before 20260508, the distfile is not
# fetchable by ftp/wget/curl.
# Reported upstream by to the chirp list
#   20260508
#   20260515
# but this report seems not to have reached the list.
#
# The workaround is to fetch manually and then:
#   make upload-distfiles
MASTER_SITES=	https://trac.chirp.danplanet.com/chirp_next/next-${VERSION}/
# Chirp does not have what would normally called releases.  They have
# "daily builds" which are like releases except that:
#   they are called chirp-next instead of chirp
#   they have YYYYMMDD version numbers
#   they don't have the usual release testing
# They do have a history of stability.
# Upstream says
#    they will not go back to regular version numbers
#    the preferred name is chirp, not chirp-next or chipr-daily
# via
#   https://chirp.danplanet.com/issues/8067
#   https://chirp.danplanet.com/news/15
#   discussions on their mailinglist

MAINTAINER=	gdt@NetBSD.org
#MAINTAINER+=	dbj@NetBSD.org
HOMEPAGE=	https://chirpmyradio.com/projects/chirp/wiki/Home
COMMENT=	Tool for programming Amateur Radio HTs
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	#none

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# setup.py:install_requires (generally without a version)
DEPENDS+=	${PYPKGPREFIX}-serial>=2.7:../../comms/py-serial
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yattag>=1.15.1:../../textproc/py-yattag
DEPENDS+=	${PYPKGPREFIX}-suds>=1.0:../../net/py-suds
DEPENDS+=	${PYPKGPREFIX}-lark>=1.0:../../lang/py-lark

# setup.py:extras_require
DEPENDS+=	${PYPKGPREFIX}-wxPython>=4:../../x11/py-wxPython

.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
