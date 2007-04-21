# $NetBSD: Makefile,v 1.2 2007/04/21 11:50:36 wiz Exp $

DISTNAME=	e871e108f2e4
PKGNAME=	${RUBY_PKGPREFIX}-rcsparse-0.0.0.37
CATEGORIES=	devel ruby
MASTER_SITES=	http://ww2.fs.ei.tum.de/~corecode/hg/rcsparse/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/rcsparse/
COMMENT=	RCS parsing library for Ruby

LICENSE=	corecode-license

DIST_SUBDIR=	rcsparse
WRKSRC=		${WRKDIR}/rcsparse-${DISTNAME}
USE_RUBY_EXTCONF=	yes

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
