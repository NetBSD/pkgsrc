# $NetBSD: Makefile,v 1.2 2006/04/12 00:44:37 minskim Exp $

DISTNAME=	ko-po-check-0.5
CATEGORIES=	devel korean textproc
MASTER_SITES=	http://kldp.net/frs/download.php/929/

MAINTAINER=	junyoung@mogua.com
HOMEPAGE=	http://ko-po-check.kldp.net/
COMMENT=	Korean .po file checker

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=	${WRKSRC}/scripts/ko-po-check.in

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
