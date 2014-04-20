# $NetBSD: Makefile,v 1.8 2014/04/20 12:44:01 imil Exp $
#

IRCVERS=	8.5.4
DISTNAME=	irc-${IRCVERS}
PKGNAME=	${PYPKGPREFIX}-irclib-${IRCVERS}
PKGREVISION=	4
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/i/irc/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://bitbucket.org/jaraco/irc
COMMENT=	Internet Relay Chat (IRC) protocol client library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six

BUILD_DEPENDS+=	${PYPKGPREFIX}-hgtools>=2.0.2:../../devel/py-hgtools

.include "../../lang/python/distutils.mk"

PLIST_VARS+=	requires
.if ${PYVERSSUFFIX} == "2.5" || ${PYVERSSUFFIX} == "2.6"
PLIST.requires=	yes
.endif

post-extract:
	cd ${WRKSRC} && ${CHMOD} ${SHAREMODE} irc.egg-info/*

.include "../../mk/bsd.pkg.mk"
