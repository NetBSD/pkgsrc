# $NetBSD: Makefile,v 1.6 2001/05/24 08:53:57 jlam Exp $
#

DISTNAME=	calc-2.11.4t2
PKGNAME=	capc-${DISTNAME:S/t/./}
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		ftp://ftp.batnet.com/wombats/noll/ftp/pub/calc/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

NO_CONFIGURE=	# defined

.include "../../devel/readline/buildlink.mk"

MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${BUILDLINK_INCDIR}
LDFLAGS+=	-L${BUILDLINK_LIBDIR}

pre-build: ${BUILDLINK_TARGETS}

.include "../../mk/bsd.pkg.mk"
