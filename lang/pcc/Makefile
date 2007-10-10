# $NetBSD: Makefile,v 1.5 2007/10/10 13:15:59 reed Exp $

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

INSTALLATION_DIRS=	bin libexec

.include "../../mk/bsd.pkg.mk"
