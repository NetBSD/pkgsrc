# $NetBSD: Makefile,v 1.13 2008/09/06 14:28:43 wiz Exp $
#

DISTNAME=	clive-1.0.1
CATEGORIES=	net multimedia www
MASTER_SITES=	http://download.gna.org/clive/1.0.x/ \
		${MASTER_SITE_SOURCEFORGE:=clive/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://clive.sourceforge.net/
COMMENT=	Command line video extraction tool for user-uploaded video hosts

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2
DEPENDS+=	${PYPKGPREFIX}-newt>=0.51:../../devel/py-newt
DEPENDS+=	${PYPKGPREFIX}-m2crypto-[0-9]*:../../security/py-m2crypto
DEPENDS+=	${PYPKGPREFIX}-feedparser>=4.1:../../textproc/py-feedparser
DEPENDS+=	urlgrabber>=3.1.0:../../www/urlgrabber

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c # configure script
PY_PATCHPLIST=			yes

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	src/scripts/clive

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
