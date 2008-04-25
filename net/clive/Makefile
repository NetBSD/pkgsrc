# $NetBSD: Makefile,v 1.5 2008/04/25 20:39:11 joerg Exp $
#

DISTNAME=	clive-0.4.10
CATEGORIES=	net multimedia www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clive/} \
		http://dl.gna.org/clive/0.4/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://clive.sourceforge.net/
COMMENT=	Command line video extraction tool for user-uploaded video hosts

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
PY_PATCHPLIST=			yes

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	src/clive/feedparser/feedparser.py
REPLACE_FILES.env_python+=	src/scripts/clive

.include "../../devel/libslang/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
