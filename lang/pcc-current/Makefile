# $NetBSD: Makefile,v 1.7 2011/02/25 12:21:09 he Exp $

PKGNAME=	pcc-current-1.0.0.BETA.${DATE_STR}
DISTPREFIX=	pcc-1.0.0.BETA
DISTNAME=	${DISTPREFIX}-${DATE_STR}
DATE_STR=	20110225
WRKSRC=		${WRKDIR}/${DISTPREFIX}
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc-beta/
EXTRACT_SUFX=	.tgz

PKG_DESTDIR_SUPPORT=	user-destdir

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler

LICENSE=	pcc-license

CONFLICTS=	pcc-[0-9]*

USE_TOOLS+=	lex yacc
# XXX For some reason building with bmake fails randomly.
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
