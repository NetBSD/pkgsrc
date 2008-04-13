# $NetBSD: Makefile,v 1.3 2008/04/13 09:58:48 wiz Exp $
#

DISTNAME=	clive-0.4.9
CATEGORIES=	net multimedia www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clive/} \
		http://dl.gna.org/clive/0.4/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://clive.sourceforge.net/
COMMENT=	Command line video extraction tool for user-uploaded video hosts

DEPENDS+=	${PYPKGPREFIX}-newt-[0-9]*:../../devel/py-newt

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	24 23 22
PY_PATCHPLIST=			yes

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	src/clive/feedparser/feedparser.py
REPLACE_FILES.env_python+=	src/scripts/clive run-tests.py run.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
