# $NetBSD: Makefile,v 1.13 2008/06/21 10:12:59 taca Exp $

DISTNAME=	ruby-romkan-0.4
PKGNAME=	${RUBY_PKGPREFIX}-romkan-0.4
PKGREVISION=	2
CATEGORIES=	converters japanese ruby
MASTER_SITES=	http://0xcc.net/ruby-romkan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0xcc.net/ruby-romkan/
COMMENT=	Romaji <-> Kana conversion library for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
DOCS=		romkan.html romkan.html.ja romkan.en.rd romkan.ja.rd
INSTALLATION_DIRS=	${RUBY_DOC}/romkan ${RUBY_VENDORLIB}

do-build:
	cd ${WRKSRC}; ${RUBY_RD} romkan.en.rd > romkan.html
	cd ${WRKSRC}; ${RUBY_RD} romkan.ja.rd > romkan.html.ja

do-install:
	${INSTALL_DATA} ${WRKSRC}/romkan.rb ${DESTDIR}${PREFIX}/${RUBY_VENDORLIB}
.for f in ${DOCS}
	cd ${WRKSRC}; ${INSTALL_DATA} ${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/romkan
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
