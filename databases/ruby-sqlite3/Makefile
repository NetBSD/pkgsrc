# $NetBSD: Makefile,v 1.1.1.1 2006/03/30 16:21:14 minskim Exp $

DISTNAME=	sqlite3-ruby-1.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-ruby//}
CATEGORIES=	databases
MASTER_SITES=	http://rubyforge.org/frs/download.php/3089/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://sqlite-ruby.rubyforge.org/
COMMENT=	Ruby interface for the SQLite database engine

USE_RUBY_SETUP=	yes

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
