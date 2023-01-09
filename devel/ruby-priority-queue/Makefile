# $NetBSD: Makefile,v 1.12 2023/01/09 06:30:13 taca Exp $

DISTNAME=	PriorityQueue-0.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/PriorityQueue/priority-queue/}
PKGREVISION=	4
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	# http://rubyforge.org/projects/priority-queue/
COMMENT=	Fibonacci-heap priority-queue implementation for Ruby
LICENSE=	gnu-gpl-v2 OR ruby-license

OVERRIDE_GEMSPEC=	:files priority_queue.so= priority_queue.o=

# Dose not support newer versions.
RUBY_VERSIONS_ACCEPTED=	27 30

pre-configure:
	cd ${WRKSRC} && pwd; ${RM} -f priority_queue.so priority_queue.o

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
