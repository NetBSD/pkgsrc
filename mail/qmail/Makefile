# $NetBSD: Makefile,v 1.15 2002/09/18 21:15:12 jlam Exp $
#

DISTNAME=	qmail-1.03
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/			\
		ftp://ftp.ntnu.no/pub/unix/mail/qmail/		\
		ftp://ftp.jp.qmail.org/qmail/			\
		ftp://ftp.rifkin.technion.ac.il/pub/qmail/	\
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		ftp://ftp.id.wustl.edu/pub/qmail/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	SECURE, reliable, efficient, simple, and FAST MTA for UNIX systems

DEPENDS+=	qmail-users>=1.0:../../mail/qmail-users

ALL_TARGET= 	it man
INSTALL_TARGET=	setup check

RESTRICTED=		"djb does not permit modified binary packages"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NO_PACKAGE=		"needs work to function properly as a binary package"

OWN_DIRS+=		${QMAILDIR}

FILES_SUBST+=		QMAILDIR=${QMAILDIR}
RCD_SCRIPTS=		qmail
RCD_SCRIPTS_EXAMPLEDIR=	${QMAILDIR}/etc/rc.d

.include "../../mk/bsd.prefs.mk"

NO_MTREE=	YES
LOCALBASE=	/

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/qmail.sh			\
		> ${WRKDIR}/qmail
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf		\
		> ${WRKDIR}/mailer.conf.qmail

post-install:
	${INSTALL_DATA_DIR} ${QMAILDIR}/etc
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.qmail ${QMAILDIR}/etc

	${INSTALL_SCRIPT_DIR} ${RCD_SCRIPTS_EXAMPLEDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/qmail ${RCD_SCRIPTS_EXAMPLEDIR}

	${INSTALL_DATA_DIR} ${QMAILDIR}/alias
	cd ${QMAILDIR}/alias && 					\
		${TOUCH} .qmail-postmaster .qmail-mailer-daemon .qmail-root

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
