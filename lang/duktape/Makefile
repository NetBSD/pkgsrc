# $NetBSD: Makefile,v 1.6 2020/11/26 15:31:31 nia Exp $

DISTNAME=	duktape-2.6.0
CATEGORIES=	devel
MASTER_SITES=	https://duktape.org/
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
