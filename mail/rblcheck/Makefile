# $NetBSD: Makefile,v 1.2 1999/12/26 18:39:01 itojun Exp $
# FreeBSD: ports/mail/rblcheck/Makefile,v 1.6 1999/08/25 06:50:47 obrien Exp
#

DISTNAME=	rblcheck-1.4
CATEGORIES=	mail
MASTER_SITES=	http://www.xnet.com/%7Eemarshal/rblcheck/

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://www.xnet.com/%7Eemarshal/rblcheck/

DOCS=		BUGS CHANGES CREDITS INSTALL PLATFORMS TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rblcheck ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	dst=${PREFIX}/share/doc/rblcheck; \
	${MKDIR} $$dst; \
	for i in ${DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/docs/$$i $$dst; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
