# $NetBSD: Makefile,v 1.10 2009/08/01 20:37:05 dholland Exp $

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
# XXX For some reason building with bmake fails randomly.
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
