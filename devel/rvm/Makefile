# $NetBSD: Makefile,v 1.23 2011/03/11 20:04:46 gdt Exp $
#

DISTNAME=	rvm-1.17
CATEGORIES=	devel
MASTER_SITES=	http://ftp.coda.cs.cmu.edu/pub/rvm/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Recoverable Virtual Memory

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake pkg-config
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
