# $NetBSD: Makefile,v 1.4 2004/03/16 02:01:10 taca Exp $

DISTNAME=	ruby-romkan-0.4
CATEGORIES=	converters japanese ruby
MASTER_SITES=	http://namazu.org/~satoru/ruby-romkan/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://namazu.org/~satoru/ruby-romkan/
COMMENT=	Romaji <-> Kana conversion library for Ruby

DIST_SUBDIR=	ruby
USE_RUBY_RD=	# defined
NO_CONFIGURE=	# defined

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

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
