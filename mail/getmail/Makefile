# $NetBSD: Makefile,v 1.14 2004/03/29 08:16:38 snj Exp $

DISTNAME=	getmail-3.2.2
CATEGORIES=	mail
MASTER_SITES=	http://www.qcc.ca/~charlesc/software/getmail-3.0/ \
		http://www.qcc.ca/~charlesc/software/getmail-3.0/old-versions/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.qcc.ca/~charlesc/software/getmail-3.0/
COMMENT=	POP3 mail retriever with reliable Maildir and command delivery

NO_CONFIGURE=	YES
NO_BUILD=	YES

USE_PKGINSTALL=	YES

PYTHON_PATCH_SCRIPTS=	ConfParser.py getmail.py getmail_classes.py
PYTHON_PATCH_SCRIPTS+=	getmail_constants.py getmail_defaults.py
PYTHON_PATCH_SCRIPTS+=	getmail_utilities.py
PYTHON_PATCH_SCRIPTS+=	getmail_maildir
PYTHON_PATCH_SCRIPTS+=	getmail_mbox getmail_mbox.py

OWN_DIRS=	${PREFIX}/share/doc/getmail
OWN_DIRS+=	${PREFIX}/share/doc/html/getmail
OWN_DIRS+=	${PREFIX}/libexec/getmail

post-patch:
	@${SED} "s,/usr/lib,${PREFIX}/libexec," ${WRKSRC}/getmail	\
		> ${WRKSRC}/getmail.done1
	@${SED} "s,\`which python\`,${PYTHONBIN}," <${WRKSRC}/getmail.done1 \
		> ${WRKSRC}/getmail.done2
	@${MV} ${WRKSRC}/getmail.done2 ${WRKSRC}/getmail
	@${MV} ${WRKSRC}/getmail_maildir ${WRKSRC}/getmail_maildir.tmp
	@${SED} "s,/usr/lib,${PREFIX}/libexec," ${WRKSRC}/getmail_maildir.tmp \
		> ${WRKSRC}/getmail_maildir
	@${MV} ${WRKSRC}/getmail_mbox ${WRKSRC}/getmail_mbox.tmp
	@${SED} "s,/usr/lib,${PREFIX}/libexec," ${WRKSRC}/getmail_mbox.tmp \
		> ${WRKSRC}/getmail_mbox

do-install:
	${INSTALL_SCRIPT_DIR} ${PREFIX}/libexec/getmail
	cd ${WRKSRC} &&							\
	${INSTALL_SCRIPT} ConfParser.py getmail.py getmail_classes.py	\
		getmail_constants.py getmail_defaults.py		\
		getmail_utilities.py timeoutsocket.py			\
		getmail_maildir getmail_mbox getmail_mbox.py		\
		${PREFIX}/libexec/getmail
	${INSTALL_SCRIPT} ${WRKSRC}/getmail ${PREFIX}/bin
	${INSTALL_MAN_DIR} ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/getmail.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/getmail
	cd ${WRKSRC} &&						\
	${INSTALL_DATA} BUGS CHANGELOG COPYING THANKS TODO	\
		getmailrc-example faq.txt getmail.txt docs.txt	\
		${PREFIX}/share/doc/getmail
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/getmail
	cd ${WRKSRC} &&					\
	${INSTALL_DATA} docs.html faq.html		\
		${PREFIX}/share/doc/html/getmail
	${INSTALL_DATA} ${WRKSRC}/getmailrc-example 	\
		${PREFIX}/share/examples/getmailrc

.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
