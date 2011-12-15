# $NetBSD: Makefile,v 1.3 2011/12/15 15:06:45 taca Exp $

DISTNAME=	lockfile-2.1.0
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codeforpeople.com/lib/ruby/lockfile/
COMMENT=	Ruby library for creating NFS safe lockfiles
LICENSE=	ruby-license

post-install:
	${MV} -f ${DESTDIR}${PREFIX}/bin/rlock \
		${DESTDIR}${PREFIX}/bin/rlock${RUBY_VER}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
