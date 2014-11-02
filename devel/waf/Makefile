# $NetBSD: Makefile,v 1.5 2014/11/02 18:13:24 wiz Exp $

DISTNAME=	waf-1.8.4
CATEGORIES=	devel
MASTER_SITES=	http://ftp.waf.io/pub/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/waf/
COMMENT=	Framework for configuring, compiling and installing applications
LICENSE=	modified-bsd

REPLACE_PYTHON=		waf-light
INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf-light configure build

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/waf ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
