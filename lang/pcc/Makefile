# $NetBSD: Makefile,v 1.9 2009/04/30 20:17:03 zafer Exp $

DISTNAME=	pcc-0.9.9
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc/ \
		http://pcc.ludd.ltu.se/ftp/pub/pcc/
EXTRACT_SUFX=	.tgz

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler

USE_TOOLS+=	lex yacc
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
