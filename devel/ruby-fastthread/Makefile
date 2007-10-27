# $NetBSD: Makefile,v 1.2 2007/10/27 04:49:04 minskim Exp $

DISTNAME=	fastthread-1.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/27041/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Optimized replacement for thread.rb primitives

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
