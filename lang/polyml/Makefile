# $NetBSD: Makefile,v 1.19 2019/05/02 18:24:58 alnsn Exp $

DISTNAME=	polyml-5.7.1
CATEGORIES=	lang
MASTER_SITES=   ${MASTER_SITE_GITHUB:=polyml/}
GITHUB_PROJECT= polyml
GITHUB_TAG=     v${PKGVERSION_NOREV}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://polyml.org/
COMMENT=	Poly/ML is an implementation of Standard ML

# ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc

NOT_PAX_ASLR_SAFE+=	bin/poly
NOT_PAX_MPROTECT_SAFE+= bin/poly

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libffi
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
TEST_TARGET=	tests

PKGCONFIG_OVERRIDE=	libpolyml/polyml.pc.in

.include "options.mk"

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
