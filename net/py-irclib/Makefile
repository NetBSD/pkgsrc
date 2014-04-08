# $NetBSD: Makefile,v 1.4 2014/04/08 16:40:35 imil Exp $
#

IRCVERS=	8.5.4
DISTNAME=	irc-${IRCVERS}
PKGNAME=	${PYPKGPREFIX}-irclib-${IRCVERS}
CATEGORIES=	net python
MASTER_SITES=	http://pypi.python.org/packages/source/i/irc/
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://bitbucket.org/jaraco/irc
COMMENT=	Internet Relay Chat (IRC) protocol client library
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

PLIST_VARS+=	requires
.if ${PYVERSSUFFIX} == "2.5" || ${PYVERSSUFFIX} == "2.6"
PLIST.requires=	yes
.endif

post-extract:
	cd ${WRKSRC} && ${CHMOD} ${SHAREMODE} irc.egg-info/*

# for some reason, this package does not install egg infos
post-install:
	${INSTALL_DATA} ${WRKSRC}/irc.egg-info/*		\
		${DESTDIR}${PREFIX}/${PYSITELIB}/${EGG_INFODIR}

.include "../../devel/py-hgtools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
