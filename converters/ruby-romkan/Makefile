# $NetBSD: Makefile,v 1.6 2005/03/06 17:19:05 taca Exp $

DISTNAME=	ruby-romkan-0.4
PKGNAME=	${RUBY_PKGPREFIX}-romkan-0.4
PKGREVISION=	1
CATEGORIES=	converters japanese ruby
MASTER_SITES=	http://namazu.org/~satoru/ruby-romkan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://namazu.org/~satoru/ruby-romkan/
COMMENT=	Romaji <-> Kana conversion library for Ruby

USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

do-build:
	cd ${WRKSRC}; ${RUBY_RD} romkan.en.rd > romkan.html
	cd ${WRKSRC}; ${RUBY_RD} romkan.ja.rd > romkan.html.ja

do-install:
	${INSTALL_DATA} ${WRKSRC}/romkan.rb ${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.html ${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.html.ja ${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.en.rd ${RUBY_DOCDIR}/romkan/romkan.rd
	${INSTALL_DATA} ${WRKSRC}/romkan.ja.rd ${RUBY_DOCDIR}/romkan

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
