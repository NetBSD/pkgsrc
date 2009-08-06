# $NetBSD: Makefile,v 1.4 2009/08/06 06:40:31 hasso Exp $

DISTNAME=	pcc-${DATE_STR}
PKGNAME=	pcc-current-0.9.9.20${DATE_STR}
DATE_STR=	090731
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc/
EXTRACT_SUFX=	.tgz

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler

CONFLICTS=	pcc-[0-9]*

USE_TOOLS+=	lex yacc
# XXX For some reason building with bmake fails randomly.
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
