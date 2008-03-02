# $NetBSD: Makefile,v 1.1.1.1 2008/03/02 12:13:38 he Exp $

DISTNAME=	pcc-${DATE_STR}
PKGNAME=	pcc-current-0.9.9.20${DATE_STR}
DATE_STR=	080223
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler

CONFLICTS=	pcc-[0-9]*

USE_TOOLS+=	lex yacc
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
