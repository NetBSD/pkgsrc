# $NetBSD: Makefile,v 1.8 2002/09/21 23:46:52 jlam Exp $
#

DISTNAME=	getmail-2.1.3
CATEGORIES=	mail
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/getmail-2.0/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.qcc.sk.ca/~charlesc/software/getmail-2.0/
COMMENT=	POP3 mail retriever with reliable Maildir and mbox delivery

NO_CONFIGURE=	YES
NO_BUILD=	YES

PYTHON_PATCH_SCRIPTS=	ConfParser.py getmail.py

post-patch:
	${SED} "s,/usr/lib,${PREFIX}/libexec," ${WRKSRC}/getmail	\
		> ${WRKSRC}/getmail.done1
	${SED} "s,\`which python\`,${PYTHONBIN}," <${WRKSRC}/getmail.done1 \
		> ${WRKSRC}/getmail.done2
	${MV} ${WRKSRC}/getmail.done2 ${WRKSRC}/getmail

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/getmail
	cd ${WRKSRC} &&							\
	${INSTALL_DATA} TODO BUGS CHANGELOG getmailrc-example faq.txt	\
		getmail.txt docs.txt COPYING ${PREFIX}/share/doc/getmail
	${INSTALL_DATA} ${WRKSRC}/getmailrc-example 			\
		${PREFIX}/share/examples/getmailrc
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/getmail
	cd ${WRKSRC} &&							\
	${INSTALL_SCRIPT} ConfParser.py timeoutsocket.py getmail.py	\
		${PREFIX}/libexec/getmail
	${INSTALL_SCRIPT} ${WRKSRC}/getmail ${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
