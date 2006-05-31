# $NetBSD: Makefile,v 1.2 2006/05/31 04:11:02 taca Exp $

DISTNAME=	priority-queue-0.1.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ruby.brian-schroeder.de/priority-queue/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ruby.brian-schroeder.de/priority-queue/releases/
COMMENT=	Fibonacci-heap priority-queue implementation for Ruby

RUBY_HAS_ARCHLIB= yes
USE_RUBY_SETUP=	yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
