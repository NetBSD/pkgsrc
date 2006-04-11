# $NetBSD: Makefile,v 1.1.1.1 2006/04/11 17:40:01 minskim Exp $

DISTNAME=	ko-po-check-0.5
CATEGORIES=	devel korean
MASTER_SITES=	http://kldp.net/frs/download.php/929/

MAINTAINER=	junyoung@mogua.com
HOMEPAGE=	http://ko-po-check.kldp.net/
COMMENT=	Korean .po file checker

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=	${WRKSRC}/scripts/ko-po-check.in

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
