# $NetBSD: Makefile,v 1.8.4.1 2011/02/27 00:26:13 tron Exp $

DISTNAME=	ruby-odbc-0.99992
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.ch-werner.de/rubyodbc/
# needs EXTRACT_SUFX since DISTFILE isn't Ruby's gem format.
EXTRACT_SUFX=  .tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ch-werner.de/rubyodbc/
COMMENT=	ODBC binding for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS=	--disable-dlopen

pre-patch:
	mv ${WRKSRC}/ruby-odbc.gemspec ${GEM_SPECFILE}

.include "options.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
