# $NetBSD: Makefile,v 1.6 2009/02/15 18:53:02 wiz Exp $

DISTNAME=	0aa8fb608963
PKGNAME=	${RUBY_PKGPREFIX}-rcsparse-0.0.0.43
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
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
