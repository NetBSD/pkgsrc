# $NetBSD: Makefile,v 1.4 2022/07/18 12:44:47 jperkin Exp $

DISTNAME=		ronn-0.7.3
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		2
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

post-build:
	${SED} -e 's/ronn(1)/ronn${RUBY_SUFFIX}(1)/g' \
	    -e 's/ronn\\-format(7)/ronn\-format${RUBY_SUFFIX}(7)/g' \
	    ${WRKSRC}/man/ronn.1 > \
	    ${WRKDIR}/ronn${RUBY_SUFFIX}.1
	${SED} -e 's/ronn(1)/ronn${RUBY_SUFFIX}(1)/g' \
	    -e 's/ronn\\-format(7)/ronn\-format${RUBY_SUFFIX}(7)/g' \
	    ${WRKSRC}/man/ronn-format.7 > \
	    ${WRKDIR}/ronn-format${RUBY_SUFFIX}.7

post-install:
	${INSTALL_MAN} ${WRKDIR}/ronn${RUBY_SUFFIX}.1 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ronn${RUBY_SUFFIX}.1
	${INSTALL_MAN} ${WRKDIR}/ronn-format${RUBY_SUFFIX}.7 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/ronn-format${RUBY_SUFFIX}.7

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
