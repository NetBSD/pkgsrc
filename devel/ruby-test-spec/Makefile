# $NetBSD: Makefile,v 1.4 2017/09/04 18:00:54 wiz Exp $

DISTNAME=	test-spec-0.10.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://test-spec.rubyforge.org/test-spec/
COMMENT=	BDD interface over Test::Unit
LICENSE=	gnu-gpl-v2 OR ruby-license

post-extract:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} g-w {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
