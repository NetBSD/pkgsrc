# $NetBSD: Makefile,v 1.5 2008/02/08 15:13:54 obache Exp $

DISTNAME=	sqlite3-ruby-1.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/17096/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

DOCS=	ChangeLog LICENSE README

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR:Q}/sqlite3/api
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC:Q}/${f:Q} ${DESTDIR}${RUBY_DOCDIR:Q}/sqlite3/
.endfor
	cd ${WRKSRC:Q}/doc && ${PAX} -rw -pp * ${DESTDIR}${RUBY_DOCDIR:Q}/sqlite3
	cd ${WRKSRC:Q}/api && ${PAX} -rw -pp * ${DESTDIR}${RUBY_DOCDIR:Q}/sqlite3/api

.include "../../mk/bsd.pkg.mk"
