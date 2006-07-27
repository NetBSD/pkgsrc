# $NetBSD: Makefile,v 1.3 2006/07/27 18:22:55 minskim Exp $

DISTNAME=	ko-po-check-0.7
CATEGORIES=	devel korean textproc
MASTER_SITES=	http://kldp.net/frs/download.php/3463/

MAINTAINER=	junyoung@mogua.com
HOMEPAGE=	http://ko-po-check.kldp.net/
COMMENT=	Korean .po file checker

GNU_CONFIGURE=	yes

PYTHON_VERSIONS_INCOMPATIBLE+=	23 22 21 20 15
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=	${WRKSRC}/scripts/ko-po-check.in

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
