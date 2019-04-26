# $NetBSD: Makefile,v 1.20 2019/04/26 14:12:35 maya Exp $

DISTNAME=	ko-po-check-0.8
PKGREVISION=	4
CATEGORIES=	devel korean textproc
MASTER_SITES=	http://kldp.net/frs/download.php/3863/

MAINTAINER=	junyoung@mogua.com
HOMEPAGE=	http://ko-po-check.kldp.net/
COMMENT=	Korean .po file checker

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

REPLACE_PYTHON=	scripts/ko-po-check.in
PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.8

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
