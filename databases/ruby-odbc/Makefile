# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:15:50 jlam Exp $

DISTNAME=	ruby-odbc-0.9995
PKGNAME=	${RUBY_PKGPREFIX}-${GEM_NAME}
CATEGORIES=	databases
MASTER_SITES=	http://www.ch-werner.de/rubyodbc/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ch-werner.de/rubyodbc/
COMMENT=	ODBC binding for Ruby

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

GEM_NAME=	${DISTNAME:S/ruby-//}
GEM_BUILD=	gemspec
GEM_CLEANBUILD=	Makefile mkmf.log *.o odbc.${RUBY_DLEXT} utf8/*

CONFIGURE_ARGS=	--disable-dlopen

post-extract:
	cp ${FILESDIR}/gemspec ${GEM_SPECFILE}

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
