# $NetBSD: Makefile,v 1.16 2020/03/20 11:58:10 nia Exp $
#

PYIRCVERS=		11.1.1
DISTNAME=		irc-${PYIRCVERS}
PKGNAME=		${PYPKGPREFIX}-irclib-${PYIRCVERS}
CATEGORIES=		net python
MASTER_SITES=		${MASTER_SITE_PYPI:=i/irc/}
EXTRACT_SUFX=		.zip
EXTRACT_OPTS_ZIP=	-aa -q -o

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://python-irclib.sourceforge.net/
COMMENT=	Internet Relay Chat (IRC) protocol client library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-jaraco_util>=10.0.2:../../devel/py-jaraco_util

BUILD_DEPENDS+=	${PYPKGPREFIX}-hgtools>=5:../../devel/py-hgtools

.include "../../lang/python/distutils.mk"

PLIST_VARS+=	requires
.if ${PYVERSSUFFIX} == "2.5" || ${PYVERSSUFFIX} == "2.6"
PLIST.requires=	yes
.endif

post-extract:
	cd ${WRKSRC} && ${CHMOD} ${SHAREMODE} irc.egg-info/*

.include "../../mk/bsd.pkg.mk"
