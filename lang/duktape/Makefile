# $NetBSD: Makefile,v 1.2 2017/10/29 22:26:56 leot Exp $

DISTNAME=	duktape-2.2.0
CATEGORIES=	devel
MASTER_SITES=	http://duktape.org/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://duktape.org/
COMMENT=	Embeddable Javascript engine
LICENSE=	mit

do-build:
	(cd ${WRKSRC} && \
		${CC} ${CFLAGS} examples/cmdline/duk_cmdline.c \
		-Wl,-R${PREFIX}/lib -L${PREFIX}/lib -lduktape -lm -o duk)

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/duk ${DESTDIR}${PREFIX}/bin

.include "../../lang/libduktape/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
