# $NetBSD: Makefile,v 1.1.1.1 2004/07/14 20:05:50 jlam Exp $

PKGNAME=	courier-maildir-${BASE_VERS}
COMMENT=	Courier maildir utilities

CONFLICTS=	courier-maildirmake-[0-9]*

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_PKGINSTALL=		yes
USE_PERL5=		yes
PERL5_REQD+=		5.8.0
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

.include "../courier-auth/Makefile.common"

# WRKSRC_FILES is copied from ../courier-auth/Makefile.authdaemond.
WRKSRC_FILES=		config.guess config.sub configure		\
			install-sh mkinstalldirs			\
			depcomp missing sysconftool
WRKSRC_FILES+=		Makefile.in courier.spec.in courier.sysvinit.in	\
			dbobj.h.in dbobj.config.in courier/courier.c

# These are subdirectories of courier that build auxiliary libraries
# used by courier-maildirmake.
#
WRKSRC_SUBDIRS=		bdbobj gdbmobj numlib liblock unicode rfc822

# These are the parts of courier that we will be building and installing.
WRKSRC_SUBDIRS+=	maildir

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\//}

BUILD_DIRS=		${WRKSRC_SUBDIRS:S/^/${WRKSRC}\//}
INSTALL_DIRS=		${WRKSRC}/maildir

OWN_DIRS=	${PKG_SYSCONFDIR}/shared
OWN_DIRS+=	${PKG_SYSCONFDIR}/shared.tmp
CONF_FILES=	${EGDIR}/quotawarnmsg ${PKG_SYSCONFDIR}/quotawarnmsg

.include "../../mk/bdb.buildlink3.mk"

post-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/sharedindexupdate.sh	\
		> ${WRKDIR}/sharedindexupdate.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sharedindexupdate.sh		\
		${DATADIR}/sharedindexupdate
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/quotawarnmsg ${EGDIR}/quotawarnmsg
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirquota.txt	\
		${DOCDIR}/README.maildirquota.txt
	${INSTALL_DATA} ${WRKSRC}/maildir/README.sharedfolders.txt	\
		${DOCDIR}/README.sharedfolders.txt

.include "../../mk/bsd.pkg.mk"
