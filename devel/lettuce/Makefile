# $NetBSD: Makefile,v 1.4 2013/06/30 22:33:58 rodent Exp $
#

DISTNAME=	lettuce-0.2.18
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/l/lettuce/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://lettuce.it/
COMMENT=	Behaviour-driven development test tool
LICENSE=	gnu-gpl-v3

REPLACE_PYTHON=	lettuce/bin.py lettuce/plugins/autopdb.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
