# $NetBSD: Makefile,v 1.12 2004/01/22 08:24:30 grant Exp $
#

DISTNAME=	rvm-1.8
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Recoverable Virtual Memory

USE_BUILDLINK2=		YES
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-lwp-includes=${BUILDLINK_PREFIX.lwp}/include

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-build:
	cd ${WRKSRC}/rvm;						\
	for file in *.c; do						\
		${LN} -sf $${file} `${BASENAME} $${file} .c`_lwp.c;	\
	done

.include "../../devel/lwp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
