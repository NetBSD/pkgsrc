# $NetBSD: Makefile,v 1.1 2007/04/30 17:03:11 minskim Exp $

DISTNAME=	fastthread-1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/18637/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://mongrel.rubyforge.org/
COMMENT=	Optimized replacement for thread.rb primitives

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
