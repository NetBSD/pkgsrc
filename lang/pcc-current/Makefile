# $NetBSD: Makefile,v 1.14 2014/07/16 20:17:37 plunky Exp $

DISTNAME=	pcc-${DATE_STR}
PKGNAME=	pcc-current-${DATE_STR}
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler
LICENSE=	pcc-license

DATE_STR=	20140706

CONFLICTS=	pcc-[0-9]*

USE_TOOLS+=	lex yacc
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
