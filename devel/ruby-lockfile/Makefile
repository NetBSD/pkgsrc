# $NetBSD: Makefile,v 1.1.1.1 2010/09/12 01:32:55 taca Exp $

DISTNAME=	lockfile-${VERS}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://codeforpeople.com/lib/ruby/lockfile/
COMMENT=	Ruby library for creating NFS safe lockfiles
LICENSE=	ruby-license

VERS=		1.4.3

pre-configure:
	cd ${WRKSRC} && \
	${RM} -f bin/rlock-${VERS} lib/lockfile-${VERS}.rb

post-install:
	${MV} -f ${DESTDIR}${PREFIX}/bin/rlock \
		${DESTDIR}${PREFIX}/bin/rlock${RUBY_VER}

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
