# $NetBSD: Makefile,v 1.2 2001/03/16 20:53:03 zuntum Exp $
#

DISTNAME=	getmail-2.0.18
CATEGORIES=	mail
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/getmail-2.0/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.qcc.sk.ca/~charlesc/software/getmail-2.0/
COMMENT=	POP3 mail retriever with reliable Maildir and mbox delivery

DEPENDS+=	python>=1.52:../../lang/python

NO_CONFIGURE=	YES
NO_BUILD=	YES

post-patch:
	${SED} "s,@PREFIX@,${PREFIX}," ${WRKSRC}/getmail		\
		> ${WRKSRC}/getmail.done
	${MV} ${WRKSRC}/getmail.done ${WRKSRC}/getmail

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/getmail
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} TODO BUGS CHANGELOG getmailrc-example faq.txt	\
		getmail.txt docs.txt COPYING ${PREFIX}/share/doc/getmail
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/getmail
	cd ${WRKSRC} &&							\
	${INSTALL_SCRIPT} ConfParser.py timeoutsocket.py getmail.py	\
		${PREFIX}/libexec/getmail
	${INSTALL_SCRIPT} ${WRKSRC}/getmail ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
