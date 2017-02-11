# $NetBSD: Makefile,v 1.1 2017/02/11 02:08:16 kamil Exp $

DISTNAME=	radamsa-0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=aoh/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aoh/radamsa/
COMMENT=	General-purpose fuzzer
LICENSE=	mit

DEPENDS+=	owl-lisp-[0-9]*:../../lang/owl-lisp

MAKE_FLAGS+=	USR_BIN_OL=${PREFIX}/bin/ol
MAKE_FLAGS+=	PREFIX=${PREFIX}

BUILD_TARGET=	everything

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	Makefile
SUBST_VARS.manpath=	PKGMANDIR

MANCOMPRESSED=	yes

.include "../../mk/bsd.pkg.mk"
