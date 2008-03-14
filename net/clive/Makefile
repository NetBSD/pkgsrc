# $NetBSD: Makefile,v 1.2 2008/03/14 01:34:44 wiz Exp $
#

DISTNAME=	clive-0.4.6
CATEGORIES=	net multimedia www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clive/} \
		http://dl.gna.org/clive/0.4/src/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://clive.sourceforge.net/
COMMENT=	Command line video extraction tool for user-uploaded video hosts

DEPENDS+=	urlgrabber>=2.9.9:../../www/urlgrabber
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	24 23 22
PYDISTUTILSPKG=			yes
PY_PATCHPLIST=			yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
