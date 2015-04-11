# $NetBSD: Makefile,v 1.8 2015/04/11 03:05:26 rodent Exp $

DISTNAME=	ctemplate-2.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OlafvdSpek/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=OlafvdSpek/ctemplate}
COMMENT=	Simple but powerful template language for C++
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	libctemplate.pc
PKGCONFIG_OVERRIDE+=	libctemplate_nothreads.pc
PKGCONFIG_OVERRIDE_STAGE=post-build
REPLACE_PERL=		src/template-converter
REPLACE_PYTHON=		src/htmlparser/generate_fsm.py

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
