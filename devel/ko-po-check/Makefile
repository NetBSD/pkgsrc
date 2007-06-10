# $NetBSD: Makefile,v 1.5 2007/06/10 21:54:07 minskim Exp $

DISTNAME=	ko-po-check-0.8
PKGREVISION=	1
CATEGORIES=	devel korean textproc
MASTER_SITES=	http://kldp.net/frs/download.php/3863/

MAINTAINER=	junyoung@mogua.com
HOMEPAGE=	http://ko-po-check.kldp.net/
COMMENT=	Korean .po file checker

GNU_CONFIGURE=	yes

PYTHON_VERSIONS_INCOMPATIBLE+=	23 22 21 20 15
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=	${WRKSRC}/scripts/ko-po-check.in

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
