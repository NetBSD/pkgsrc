# $NetBSD: Makefile,v 1.11 2015/09/25 08:54:47 taca Exp $

DISTNAME=	PriorityQueue-0.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/PriorityQueue/priority-queue/}
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/priority-queue/
COMMENT=	Fibonacci-heap priority-queue implementation for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

OVERRIDE_GEMSPEC=	:files priority_queue.so= priority_queue.o=

pre-configure:
	cd ${WRKSRC} && pwd; ${RM} -f priority_queue.so priority_queue.o

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
