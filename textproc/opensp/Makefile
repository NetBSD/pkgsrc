# $NetBSD: Makefile,v 1.7 2001/03/31 12:13:37 zuntum Exp $
#

DISTNAME=	OpenSP-1.4
PKGNAME=	opensp-1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://openjade.sourceforge.net/doc-1.4/index.htm
COMMENT=	SGML parser, successor to "sp"

DEPENDS+=	unproven-pthreads-[0-9]*:../../devel/unproven-pthreads

CONFLICTS+=     sp-*

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-http \
		--enable-default-catalog=${PREFIX}/share/sgml/catalog
CONFIGURE_ENV+= CC="${LOCALBASE}/pthreads/bin/pgcc" \
		CXX="${LOCALBASE}/pthreads/bin/pg++"

.include "../../mk/bsd.pkg.mk"
