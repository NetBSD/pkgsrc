# $NetBSD: Makefile,v 1.5 2008/06/19 14:48:18 taca Exp $

DISTNAME=	2ea7cc31cb36
PKGNAME=	${RUBY_PKGPREFIX}-rcsparse-0.0.0.42
PKGREVISION=	1
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
