# $NetBSD: Makefile,v 1.3 2007/04/01 01:58:37 obache Exp $

DISTNAME=	sqlite3-ruby-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
PKGREVISION=	1
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/3089/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

DOCS=	ChangeLog LICENSE README

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR:Q}/sqlite3/api
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${RUBY_DOCDIR:Q}/sqlite3/
.endfor
	cd ${WRKSRC:Q}/doc && ${PAX} -rw -pp * ${RUBY_DOCDIR:Q}/sqlite3
	cd ${WRKSRC:Q}/api && ${PAX} -rw -pp * ${RUBY_DOCDIR:Q}/sqlite3/api

.include "../../mk/bsd.pkg.mk"
