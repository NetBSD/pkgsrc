# $NetBSD: Makefile,v 1.3 2001/09/27 23:18:22 jlam Exp $
#

DISTNAME=	qmail-1.03
CATEGORIES=	mail
MASTER_SITES=   http://cr.yp.to/software/			\
		ftp://ftp.ntnu.no/pub/unix/mail/qmail/		\
		ftp://ftp.jp.qmail.org/qmail/			\
		ftp://ftp.rifkin.technion.ac.il/pub/qmail/	\
		ftp://ftp.net.ohio-state.edu/pub/networking/mail/qmail/ \
		ftp://ftp.id.wustl.edu/pub/qmail/

# Patch necessary to cope with non-RFC >512 dns entries
# Since AOL has been using those, the problem has skyrocketed from minor to
# groundzero. qmail being RFC compliant need to be "fixed" to work with those
PATCH_SITES=	http://www.ckdhr.com/ckd/
PATCHFILES=	qmail-103.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	SECURE, reliable, efficient, simple, and FAST MTA for UNIX systems

.if exists(/usr/sbin/user)
USER_CMD=		/usr/sbin/user
GROUP_CMD=		/usr/sbin/group
.else
DEPENDS+=		user-[0-9]*:../../sysutils/user
USER_CMD=		${LOCALBASE}/sbin/user
GROUP_CMD=		${LOCALBASE}/sbin/group
.endif

ALL_TARGET= 	it man
INSTALL_TARGET=	setup check

IS_INTERACTIVE=	YES
NO_PACKAGE=	"Has to be compiled on target system due to installation path issue"

QMAILDIR=	/var/qmail

DEINSTALL_FILE=	${WRKDIR}/DEINSTALL

FILES_SUBST+=	QMAILDIR=${QMAILDIR}
FILES_SUBST+=	USER_CMD=${USER_CMD:Q}
FILES_SUBST+=	GROUP_CMD=${GROUP_CMD:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

PLIST_SUBST+=	QMAILDIR=${QMAILDIR}

pre-build:
	@if [ `id -u` != 0 ]; then				\
		${ECHO} "Error: must be root to build qmail.";	\
		exit 1;						\
	fi
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/checkusers.sh 	\
		> ${WRKDIR}/checkusers.sh
	${SH} ${WRKDIR}/checkusers.sh

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${LN} -sf ${QMAILDIR} ${PREFIX}/qmail

post-install:
	${MKDIR} ${QMAILDIR}/alias
	cd ${QMAILDIR}/alias && 				\
		${TOUCH} .qmail-postmaster .qmail-mailer-daemon .qmail-root

remove-users: extract
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/removeusers.sh	\
		> ${WRKDIR}/removeusers.sh
	${SH} ${WRKDIR}/removeusers.sh

remove-dirs:
	${RM} -rf ${QMAILDIR}

.include "../../mk/bsd.pkg.mk"
