# $NetBSD: Makefile,v 1.9 2011/06/14 09:54:55 obache Exp $

DISTNAME=	ko-po-check-0.8
PKGREVISION=	2
CATEGORIES=	devel korean textproc
MASTER_SITES=	http://kldp.net/frs/download.php/3863/

MAINTAINER=	junyoung@mogua.com
HOMEPAGE=	http://ko-po-check.kldp.net/
COMMENT=	Korean .po file checker

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}

PYTHON_PATCH_SCRIPTS=	${WRKSRC}/scripts/ko-po-check.in

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
