# $NetBSD: Makefile,v 1.9 2013/07/07 15:56:50 taca Exp $

DISTNAME=	PriorityQueue-0.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/PriorityQueue/priority-queue/}
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/priority-queue/
COMMENT=	Fibonacci-heap priority-queue implementation for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

GEM_CLEANBUILD=		ext/priority_queue/CPriorityQueue.${RUBY_DLEXT} \
			ext/priority_queue/Makefile *.o
OVERRIDE_GEMSPEC=	:files priority_queue.so= priority_queue.o=

pre-configure:
	cd ${WRKSRC} && pwd; ${RM} -f priority_queue.so priority_queue.o

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
