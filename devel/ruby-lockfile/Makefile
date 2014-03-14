# $NetBSD: Makefile,v 1.4 2014/03/14 15:55:04 taca Exp $

DISTNAME=	lockfile-2.1.3
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ahoward/lockfile/
COMMENT=	Ruby library for creating NFS safe lockfiles
LICENSE=	ruby-license

post-install:
	${MV} -f ${DESTDIR}${PREFIX}/bin/rlock \
		${DESTDIR}${PREFIX}/bin/rlock${RUBY_SUFFIX}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
