# $NetBSD: Makefile,v 1.5 2001/05/16 20:28:40 jlam Exp $
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

.include "../../devel/readline/Makefile.readline"

MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${WRKINCDIR}
LDFLAGS+=	-L${WRKLIBDIR}

pre-build: link-readline-headers link-readline-libs

.include "../../mk/bsd.pkg.mk"
