# $NetBSD: Makefile,v 1.8 2009/02/09 22:56:22 joerg Exp $

DISTNAME=	ko-po-check-0.8
PKGREVISION=	2
CATEGORIES=	devel korean textproc
MASTER_SITES=	http://kldp.net/frs/download.php/3863/

MAINTAINER=	junyoung@mogua.com
HOMEPAGE=	http://ko-po-check.kldp.net/
COMMENT=	Korean .po file checker

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

PYTHON_VERSIONS_ACCEPTED=	25 24
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=	${WRKSRC}/scripts/ko-po-check.in

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
