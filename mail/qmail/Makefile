# $NetBSD: Makefile,v 1.23 2004/04/24 05:29:36 schmonz Exp $
#

DISTNAME=	qmail-1.03
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://cr.yp.to/software/			\
		ftp://ftp.ntnu.no/pub/unix/mail/qmail/		\
		ftp://ftp.jp.qmail.org/qmail/			\
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	Secure, reliable, efficient, simple, and fast MTA for UNIX systems

DEPENDS+=	checkpassword-[0-9]*:../../sysutils/checkpassword
DEPENDS+=	qmail-users>=1.0:../../mail/qmail-users
DEPENDS+=	ucspi-tcp-[0-9]*:../../net/ucspi-tcp

USE_BUILDLINK3=	yes

ALL_TARGET= 	it man
INSTALL_TARGET=	setup check

RESTRICTED=		"djb does not permit modified binary packages"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NO_PACKAGE=		"needs work to function properly as a binary package"

USE_PKGINSTALL=		yes
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
OWN_DIRS+=		${QMAILDIR}

EVAL_PREFIX+=		LOCALBASE_NORMAL=ucspi-tcp

FILES_SUBST+=		QMAILDIR=${QMAILDIR}
FILES_SUBST+=		LOCALBASE_NORMAL=${LOCALBASE_NORMAL}
RCD_SCRIPTS=		qmail qmailsmtpd qmailpop3d
RCD_SCRIPTS_EXAMPLEDIR=	${QMAILDIR}/etc/rc.d

.include "../../mk/bsd.prefs.mk"

NO_MTREE=	YES
LOCALBASE=	/

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailer.conf		\
		> ${WRKDIR}/mailer.conf.qmail

post-install:
	${INSTALL_DATA_DIR} ${QMAILDIR}/etc
	${INSTALL_DATA} ${WRKDIR}/mailer.conf.qmail ${QMAILDIR}/etc

	${INSTALL_DATA_DIR} ${QMAILDIR}/alias
	cd ${QMAILDIR}/alias && 					\
		${TOUCH} .qmail-postmaster .qmail-mailer-daemon .qmail-root

.include "../../mk/bsd.pkg.mk"
