# $NetBSD: Makefile,v 1.1.1.2 2001/03/26 22:34:55 jtb Exp $

DISTNAME=	yodl-1.31.18
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.lilypond.org/pub/yodl/development/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://www.xs4all.nl/~jantien/yodl/
COMMENT=	high-level document document preparation system

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKEFILE=	GNUmakefile

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} LDFLAGS="${LDFLAGS}"

.include "../../mk/bsd.pkg.mk"
