# $NetBSD: Makefile,v 1.21 2007/04/11 18:20:14 gdt Exp $
#

DISTNAME=	rvm-1.14
CATEGORIES=	devel
MASTER_SITES=	http://ftp.coda.cs.cmu.edu/pub/rvm/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Recoverable Virtual Memory

USE_TOOLS+=		gmake
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-lwp-includes=${BUILDLINK_PREFIX.lwp}/include

pre-build:
	cd ${WRKSRC}/rvm;						\
	for file in *.c; do						\
		${LN} -sf $${file} `${BASENAME} $${file} .c`_lwp.c;	\
	done

.include "../../devel/lwp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
