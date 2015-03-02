# $NetBSD: Makefile,v 1.10 2015/03/02 09:44:05 imil Exp $
#

IRCVERS=	12.1
DISTNAME=	irc-${IRCVERS}
PKGNAME=	${PYPKGPREFIX}-irclib-${IRCVERS}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/i/irc/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://python-irclib.sourceforge.net/
COMMENT=	Internet Relay Chat (IRC) protocol client library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-jaraco_util>=10.0.2:../../devel/py-jaraco_util

BUILD_DEPENDS+=	${PYPKGPREFIX}-hgtools>=2.0.2:../../devel/py-hgtools

.include "../../lang/python/distutils.mk"

PLIST_VARS+=	requires
.if ${PYVERSSUFFIX} == "2.5" || ${PYVERSSUFFIX} == "2.6"
PLIST.requires=	yes
.endif

post-extract:
	cd ${WRKSRC} && ${CHMOD} ${SHAREMODE} irc.egg-info/*

.include "../../mk/bsd.pkg.mk"
