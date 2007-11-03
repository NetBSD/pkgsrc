# $NetBSD: Makefile,v 1.6 2007/11/03 22:38:48 rillig Exp $

DISTNAME=	pcc-0.9.8-070912
PKGNAME=	pcc-0.9.8
CATEGORIES=	lang
MASTER_SITES=	ftp://226.net120.skekraft.net/pcc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.ludd.ltu.se/~ragge/pcc/
COMMENT=	Portable C compiler

USE_TOOLS+=	lex yacc
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS=	bin libexec

.include "../../mk/bsd.pkg.mk"
