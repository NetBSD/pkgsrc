# $NetBSD: Makefile,v 1.3 2000/08/31 17:21:58 dmcmahill Exp $
#

DISTNAME=	gwave-20000809
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.unc.edu/~tell/dist/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.cs.unc.edu/~tell/gwave/

DEPENDS+=	guile-gtk>=0.19:../../devel/guile-gtk
DEPENDS+=	plotutils-*:../../graphics/plotutils

GNU_CONFIGURE=	YES

post-extract:
	${CP} ${FILESDIR}/sp2sp.1 ${WRKSRC}/doc/sp2sp.1

.include "../../mk/bsd.pkg.mk"
