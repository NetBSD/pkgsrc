# $NetBSD: Makefile,v 1.4 2001/11/26 22:22:19 zuntum Exp $
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

DEPENDS+=	qmail-users>=1.0:../../mail/qmail-users

ALL_TARGET= 	it man
INSTALL_TARGET=	setup check

IS_INTERACTIVE=	YES
NO_PACKAGE=	"Has to be compiled on target system due to installation path issue"

QMAILDIR=	/var/qmail

OWN_DIRS+=	${QMAILDIR}

DEINSTALL_EXTRA_TMPL=	${PKGDIR}/DEINSTALL

pre-build:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

pre-install:
	${LN} -sf ${QMAILDIR} ${PREFIX}/qmail

post-install:
	${MKDIR} ${QMAILDIR}/alias
	cd ${QMAILDIR}/alias && 				\
		${TOUCH} .qmail-postmaster .qmail-mailer-daemon .qmail-root

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
