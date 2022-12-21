# $NetBSD: Makefile,v 1.27 2022/12/21 11:51:21 wiz Exp $

DISTNAME=	polyml-5.8.1
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=polyml/}
GITHUB_PROJECT=	polyml
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://polyml.org/
COMMENT=	Implementation of Standard ML

# ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64 *-*-sparc *-*-powerpc

NOT_PAX_ASLR_SAFE+=	bin/poly
NOT_PAX_MPROTECT_SAFE+=	bin/poly

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libffi
USE_LIBTOOL=	yes
USE_LANGUAGES=	c gnu++03
TEST_TARGET=	tests

PKGCONFIG_OVERRIDE=	libpolyml/polyml.pc.in

.include "options.mk"

.include "../../devel/libffi/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
