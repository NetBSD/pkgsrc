# $NetBSD: Makefile,v 1.2 2011/11/08 15:44:14 taca Exp $

DISTNAME=	lockfile-${VERS}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codeforpeople.com/lib/ruby/lockfile/
COMMENT=	Ruby library for creating NFS safe lockfiles
LICENSE=	ruby-license

VERS=		1.4.3

pre-configure:
	${CP} ${FILESDIR}/gemspec ${GEM_SPECFILE}
	cd ${WRKSRC} && \
	${RM} -f bin/rlock-${VERS} lib/lockfile-${VERS}.rb

post-install:
	${MV} -f ${DESTDIR}${PREFIX}/bin/rlock \
		${DESTDIR}${PREFIX}/bin/rlock${RUBY_VER}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
