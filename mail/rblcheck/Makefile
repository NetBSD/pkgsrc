# $NetBSD: Makefile,v 1.4 2000/11/11 17:49:26 tron Exp $
# FreeBSD: ports/mail/rblcheck/Makefile,v 1.6 1999/08/25 06:50:47 obrien Exp
#

DISTNAME=	rblcheck-1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rblcheck/} \
		http://www.xnet.com/%7Eemarshal/rblcheck/

MAINTAINER=	itojun@itojun.org
HOMEPAGE=	http://rblcheck.sourceforge.net/

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
