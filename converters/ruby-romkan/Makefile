# $NetBSD: Makefile,v 1.11 2008/03/03 05:51:08 jlam Exp $

DISTNAME=	ruby-romkan-0.4
PKGNAME=	${RUBY_PKGPREFIX}-romkan-0.4
PKGREVISION=	1
CATEGORIES=	converters japanese ruby
MASTER_SITES=	http://0xcc.net/ruby-romkan/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0xcc.net/ruby-romkan/
COMMENT=	Romaji <-> Kana conversion library for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

do-build:
	cd ${WRKSRC}; ${RUBY_RD} romkan.en.rd > romkan.html
	cd ${WRKSRC}; ${RUBY_RD} romkan.ja.rd > romkan.html.ja

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/romkan.rb ${DESTDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.html ${DESTDIR}${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.html.ja ${DESTDIR}${RUBY_DOCDIR}/romkan
	${INSTALL_DATA} ${WRKSRC}/romkan.en.rd ${DESTDIR}${RUBY_DOCDIR}/romkan/romkan.rd
	${INSTALL_DATA} ${WRKSRC}/romkan.ja.rd ${DESTDIR}${RUBY_DOCDIR}/romkan

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
