# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:43 jlam Exp $

DISTNAME=	ruby-romkan-0.4
PKGNAME=	${RUBY_PKGPREFIX}-romkan-0.4
PKGREVISION=	1
CATEGORIES=	converters japanese ruby
MASTER_SITES=	http://namazu.org/~satoru/ruby-romkan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://namazu.org/~satoru/ruby-romkan/
COMMENT=	Romaji <-> Kana conversion library for Ruby

NO_CONFIGURE=	yes

do-build:
	cd ${WRKSRC}; ${RUBY_RD} romkan.en.rd > romkan.html
	cd ${WRKSRC}; ${RUBY_RD} romkan.ja.rd > romkan.html.ja

do-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/romkan.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.html ${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.html.ja ${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.en.rd ${RUBY_DOCDIR}/romkan/romkan.rd
	${INSTALL_DATA} ${WRKSRC}/romkan.ja.rd ${RUBY_DOCDIR}/romkan

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
