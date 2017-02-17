# $NetBSD: Makefile,v 1.2 2017/02/17 11:12:15 cheusov Exp $

DISTNAME=		herisvm-0.8.0
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_GITHUB:=cheusov/}

MAINTAINER=		cheusov@NetBSD.org
HOMEPAGE=		https://github.com/cheusov/herisvm
COMMENT=		svm-train wrapper running cross-validation in parallel
LICENSE=		mit

DEPENDS+=		${RUBY_BASE}-[0-9]*:${RUBY_SRCDIR}
USE_TOOLS+=		pod2man bash

SUBST_CLASSES+=		ruby
SUBST_STAGE.ruby=	pre-configure
SUBST_FILES.ruby=	scripts/*
SUBST_SED.ruby+=	-e 's|/.*ruby|${PREFIX}/bin/${RUBY_NAME}|g'
SUBST_MESSAGE.ruby=	Fixing ruby interpreter name.

REPLACE_BASH=		scripts/*

.include "../../lang/ruby/replace.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../devel/mk-configure/mk-c.mk"
.include "../../mk/bsd.pkg.mk"
