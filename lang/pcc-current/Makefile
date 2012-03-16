# $NetBSD: Makefile,v 1.10 2012/03/16 10:12:56 plunky Exp $

DISTNAME=	pcc-${DATE_STR}
PKGNAME=	pcc-current-${DATE_STR}
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler
LICENSE=	pcc-license

DATE_STR=	20120316

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	pcc-[0-9]*

USE_TOOLS+=	lex yacc
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
