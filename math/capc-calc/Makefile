# $NetBSD: Makefile,v 1.7 2001/06/10 00:08:46 jlam Exp $
#

DISTNAME=	calc-2.11.4t2
PKGNAME=	capc-${DISTNAME:S/t/./}
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		ftp://ftp.batnet.com/wombats/noll/ftp/pub/calc/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/
COMMENT=	C arbitrary precision calculator

.include "../../devel/readline/buildlink.mk"

MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${BUILDLINK_INCDIR}
LDFLAGS+=	-L${BUILDLINK_LIBDIR}

.include "../../mk/bsd.pkg.mk"
