# $NetBSD: Makefile,v 1.8 2004/07/22 00:18:43 schmonz Exp $
#

DISTNAME=	qtools-0.56
CATEGORIES=	mail
MASTER_SITES=	http://www.superscript.com/qtools/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.superscript.com/qtools/intro.html
COMMENT=	Utilities for filtering via .qmail

DEPENDS+=	{ezmlm>=0.53,ezmlm-idx-[0-9]*}:../../mail/ezmlm
DEPENDS+=	{qmail>=1.03,netqmail>=1.05}:../../mail/qmail

USE_BUILDLINK3=	yes

ALL_TARGET=	it
INSTALL_TARGET=	setup check

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-ezmlm
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
