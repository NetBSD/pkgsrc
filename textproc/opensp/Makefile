# $NetBSD: Makefile,v 1.1.1.1 2000/05/23 17:20:45 hubertf Exp $
#

DISTNAME=	OpenSP-1.4
PKGNAME=	opensp-1.4
CATEGORIES=	textproc
MASTER_SITES=	http://download.sourceforge.net/openjade/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://openjade.sourceforge.net/doc-1.4/index.htm

DEPENDS+=	unproven-pthreads-[0-9]*:../../devel/unproven-pthreads

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-http \
		--enable-default-catalog=${PREFIX}/share/sgml/catalog
CONFIGURE_ENV+= CC=${LOCALBASE}/pthreads/bin/pgcc \
		CXX=${LOCALBASE}/pthreads/bin/pg++

.include "../../mk/bsd.pkg.mk"
