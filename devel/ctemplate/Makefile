# $NetBSD: Makefile,v 1.16 2019/08/11 13:18:40 wiz Exp $

DISTNAME=	ctemplate-2.3
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OlafvdSpek/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OlafvdSpek/ctemplate
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

# In Python 3.x, print is a function, not a statement:
#	print '\n'.join(...)
# SyntaxError: invalid syntax
# https://github.com/OlafvdSpek/ctemplate/issues/137
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
