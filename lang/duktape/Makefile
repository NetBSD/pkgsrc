# $NetBSD: Makefile,v 1.3 2019/03/20 18:29:20 agc Exp $

DISTNAME=	duktape-2.3.0
CATEGORIES=	devel
MASTER_SITES=	http://duktape.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://duktape.org/
COMMENT=	Embeddable Javascript engine
LICENSE=	mit

MAKE_FILE=	Makefile.cmdline
BUILD_TARGET=	duk

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/duk ${DESTDIR}${PREFIX}/bin

.include "../../lang/libduktape/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
