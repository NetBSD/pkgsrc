# $NetBSD: Makefile,v 1.9 2002/07/03 10:59:47 jdolecek Exp $
#

DISTNAME=	rvm-1.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	phil@cs.wwu.edu
HOMEPAGE=	http://www.coda.cs.cmu.edu/
COMMENT=	Recoverable Virtual Memory

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES
USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--with-lwp-includes=${BUILDLINK_DIR}/include
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-build:
	cd ${WRKSRC}/rvm;						\
	for file in *.c; do						\
		${LN} -sf $${file} `${BASENAME} $${file} .c`_lwp.c;	\
	done

.include "../../devel/lwp/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
