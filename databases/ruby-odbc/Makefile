# $NetBSD: Makefile,v 1.4 2009/10/19 08:39:37 taca Exp $

DISTNAME=	ruby-odbc-0.9997
PKGNAME=	${RUBY_PKGPREFIX}-${GEM_NAME}
CATEGORIES=	databases
MASTER_SITES=	http://www.ch-werner.de/rubyodbc/
# needs EXTRACT_SUFX since DISTFILE isn't Ruby's gem format.
EXTRACT_SUFX=  .tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ch-werner.de/rubyodbc/
COMMENT=	ODBC binding for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

GEM_NAME=	${DISTNAME:S/ruby-//}
GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile mkmf.log *.o odbc.${RUBY_DLEXT} utf8/*

CONFIGURE_ARGS=	--disable-dlopen

post-extract:
	cp ${FILESDIR}/gemspec ${GEM_SPECFILE}

.include "options.mk"
.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
