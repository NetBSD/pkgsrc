# $NetBSD: Makefile,v 1.4 2019/06/24 10:59:42 nia Exp $

DISTNAME=	duktape-2.3.0
CATEGORIES=	devel
MASTER_SITES=	http://duktape.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://duktape.org/
COMMENT=	Embeddable Javascript engine
LICENSE=	mit

MAKE_FILE=	Makefile.cmdline
BUILD_TARGET=	duk

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/duk ${DESTDIR}${PREFIX}/bin

.include "../../lang/libduktape/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
