# $NetBSD: Makefile,v 1.10 2001/12/19 20:29:31 wiz Exp $
#

DISTNAME=	OpenSP-1.4
PKGNAME=	opensp-1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://openjade.sourceforge.net/doc-1.4/index.htm
COMMENT=	SGML parser, successor to "sp"

DEPENDS+=	unproven-pthreads-[0-9]*:../../devel/unproven-pthreads
BUILD_DEPENDS+=	perl>=5.0:../../lang/perl5

CONFLICTS+=     sp-[0-9]*

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--enable-http \
		--enable-default-catalog=${PREFIX}/share/sgml/catalog
CONFIGURE_ENV+= CC="${LOCALBASE}/pthreads/bin/pgcc" \
		CXX="${LOCALBASE}/pthreads/bin/pg++"

.include "../../mk/bsd.pkg.mk"
