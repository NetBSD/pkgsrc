# $NetBSD: Makefile,v 1.25 2020/05/31 17:16:38 rillig Exp $
#

DISTNAME=	rvm-1.17
CATEGORIES=	devel
MASTER_SITES=	http://ftp.coda.cs.cmu.edu/pub/rvm/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Recoverable Virtual Memory

USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES

pre-build:
	cd ${WRKSRC}/rvm;						\
	for file in *.c; do						\
		${LN} -sf $${file} `${BASENAME} $${file} .c`_lwp.c;	\
	done

.include "../../devel/lwp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
