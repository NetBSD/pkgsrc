# $NetBSD: Makefile,v 1.3 2003/07/21 16:56:41 martti Exp $
#

DISTNAME=	autorespond-2.0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/devel/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.inter7.com/devel/
COMMENT=	Simple autoresponder add-on package for qmail

post-patch:
	${SED} "s,\/var\/qmail,${QMAILDIR}," ${WRKSRC}/autorespond.c	\
		> ${WRKSRC}/autorespond.c.done
	${MV} ${WRKSRC}/autorespond.c.done ${WRKSRC}/autorespond.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autorespond ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/autorespond.README

.include "../../mk/bsd.pkg.mk"
