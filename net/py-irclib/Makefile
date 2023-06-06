# $NetBSD: Makefile,v 1.19 2023/06/06 12:42:07 riastradh Exp $

DISTNAME=		irc-11.1.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/irc/irclib/}
PKGREVISION=		1
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
TOOL_DEPENDS+=	${PYPKGPREFIX}-hgtools>=5:../../devel/py-hgtools

post-extract:
	cd ${WRKSRC} && ${CHMOD} ${SHAREMODE} irc.egg-info/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
