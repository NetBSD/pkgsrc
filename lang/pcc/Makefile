# $NetBSD: Makefile,v 1.7 2008/02/09 14:53:14 reed Exp $

DISTNAME=	pcc-0.9.9
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/ \
		http://pcc.ludd.ltu.se/ftp/pub/pcc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler

USE_TOOLS+=	lex yacc
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
