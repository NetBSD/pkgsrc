# $NetBSD: Makefile,v 1.4 2001/02/17 18:22:16 wiz Exp $
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

.if exists(/usr/include/readline.h) && !exists(/usr/include/readline/readline.h)
post-patch:
	${SED} -e "s|readline/readline.h|readline.h|" \
	       -e "s|readline/history.h|history.h|" ${WRKSRC}/hist.c > \
			${WRKSRC}/hist.c.new && \
	${MV} -f ${WRKSRC}/hist.c.new ${WRKSRC}/hist.c
.endif

.include "../../mk/bsd.pkg.mk"
