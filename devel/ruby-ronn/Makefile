# $NetBSD: Makefile,v 1.1 2017/08/21 13:26:14 nils Exp $

DISTNAME=		ronn-0.7.3
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		devel textproc

MAINTAINER=		nils@NetBSD.org
HOMEPAGE=		https://rtomayko.github.io/ronn/
COMMENT=		Manual authoring tool
LICENSE=		mit

DEPENDS+=		${RUBY_PKGPREFIX}-hpricot-[0-9]*:../../textproc/ruby-hpricot
DEPENDS+=		${RUBY_PKGPREFIX}-mustache-[0-9]*:../../devel/ruby-mustache
DEPENDS+=		${RUBY_PKGPREFIX}-rdiscount-[0-9]*:../../textproc/ruby-rdiscount

RUBYGEM_OPTIONS+=	--format-executable

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man7

post-install:
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/ronn.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ronn.1
	${LN} -sf ${PREFIX}/${GEM_LIBDIR}/man/ronn-format.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/ronn-format.7

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
