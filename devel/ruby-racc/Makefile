# $NetBSD: Makefile,v 1.19 2012/10/31 11:19:42 asau Exp $

DISTNAME=	racc-${RACC_VERSION}
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/49028/
EXTRACT_SUFX=	.tgz

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://i.loveruby.net/en/projects/racc/
COMMENT=	LALR(1) parser generator for Ruby
LICENSE=	gnu-lgpl-v2

CONFLICTS+=		ruby[1-9][0-9]-racc-*

USE_RUBY_SETUP=		yes
RACC_VERSION=		1.4.6

CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}
INSTALLATION_DIRS=	${RUBY_DOC}/racc/en ${RUBY_DOC}/racc/ja \
			${RUBY_EG}/racc

DOCS=		ChangeLog README.en.rdoc README.ja.rdoc TODO
EXAMPLES=	array.y array2.y calc-ja.y calc.y conflict.y hash.y lalr.y \
		lists.y syntax.y yyerr.y

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/racc
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/en/* \
		${DESTDIR}${PREFIX}/${RUBY_DOC}/racc/en
	${INSTALL_DATA} ${WRKSRC}/doc/ja/* \
		${DESTDIR}${PREFIX}/${RUBY_DOC}/racc/ja
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} \
		${DESTDIR}${PREFIX}/${RUBY_EG}/racc
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
