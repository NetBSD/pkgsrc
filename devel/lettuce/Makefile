# $NetBSD: Makefile,v 1.15 2019/09/02 13:19:36 adam Exp $

DISTNAME=	lettuce-0.2.18
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lettuce/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://lettuce.it/
COMMENT=	Behaviour-driven development test tool
LICENSE=	gnu-gpl-v3

REPLACE_PYTHON=	lettuce/bin.py lettuce/plugins/autopdb.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.2.18

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
