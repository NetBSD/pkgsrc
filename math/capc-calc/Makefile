# $NetBSD: Makefile,v 1.2 2001/02/08 15:50:20 wiz Exp $
#

DISTNAME=	calc-2.11.4t2
PKGNAME=	capc-${DISTNAME:S/t/./}
CATEGORIES=	math
MASTER_SITES=	http://www.isthe.com/chongo/src/calc/ \
		ftp://ftp.batnet.com/wombats/noll/ftp/calc/ \
		ftp://ftp.uu.net/ftp/calc/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.isthe.com/chongo/tech/comp/calc/

NO_CONFIGURE=	# defined

.if exists(/usr/include/readline.h) && !exists(/usr/include/readline/readline.h)
post-patch:
	${SED} -e "s|readline/readline.h|readline.h|" \
	       -e "s|readline/history.h|history.h|" ${WRKSRC}/hist.c > \
			${WRKSRC}/hist.c.new && \
	${MV} ${WRKSRC}/hist.c.new ${WRKSRC}/hist.c
.endif

.include "../../mk/bsd.pkg.mk"
