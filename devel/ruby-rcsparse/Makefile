# $NetBSD: Makefile,v 1.10 2011/02/21 16:01:15 taca Exp $

DISTNAME=	75d93404707d
PKGNAME=	${RUBY_PKGPREFIX}-rcsparse-0.0.0.45
PKGREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://ww2.fs.ei.tum.de/~corecode/hg/rcsparse/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ww2.fs.ei.tum.de/~corecode/hg/rcsparse/
COMMENT=	RCS parsing library for Ruby
LICENSE=	corecode-license

DIST_SUBDIR=	rcsparse
WRKSRC=		${WRKDIR}/rcsparse-${DISTNAME}
USE_RUBY_EXTCONF=	yes
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
