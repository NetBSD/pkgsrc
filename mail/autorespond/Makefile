# $NetBSD: Makefile,v 1.1.1.1 2002/01/28 22:29:49 zuntum Exp $
#

DISTNAME=	autorespond-2.0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.inter7.com/devel/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.inter7.com/devel/
COMMENT=	simple autoresponder add-on package for qmail

post-patch:
	${SED} "s,\/var\/qmail,${QMAILDIR}," ${WRKSRC}/autorespond.c	\
		> ${WRKSRC}/autorespond.c.done
	${MV} ${WRKSRC}/autorespond.c.done ${WRKSRC}/autorespond.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autorespond ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/autorespond.README

.include "../../mk/bsd.pkg.mk"
