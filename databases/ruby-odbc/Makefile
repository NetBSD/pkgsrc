# $NetBSD: Makefile,v 1.6 2010/05/27 13:46:25 taca Exp $

DISTNAME=	ruby-odbc-0.99991
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	databases
MASTER_SITES=	http://www.ch-werner.de/rubyodbc/
# needs EXTRACT_SUFX since DISTFILE isn't Ruby's gem format.
EXTRACT_SUFX=  .tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ch-werner.de/rubyodbc/
COMMENT=	ODBC binding for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_BUILD=	gemspec

CONFIGURE_ARGS=	--disable-dlopen

pre-patch:
	mv ${WRKSRC}/ruby-odbc.gemspec ${GEM_SPECFILE}

.include "options.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
