# $NetBSD: Makefile,v 1.16 2004/02/22 01:52:05 jlam Exp $

PKGNAME=	courier-maildirmake-${BASE_VERS}
COMMENT=	Courier Maildir utilities

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_PKGINSTALL=		yes
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

.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL:M-s)
INSTALL_TARGET=		install-strip
.endif

CONF_FILES=	${EGDIR}/quotawarnmsg ${PKG_SYSCONFDIR}/quotawarnmsg

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/quotawarnmsg ${EGDIR}/quotawarnmsg
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirquota.txt	\
		${DOCDIR}/README.maildirquota
	${INSTALL_DATA} ${WRKSRC}/maildir/README.sharedfolders.txt	\
		${DOCDIR}/README.sharedfolders

.include "../../mk/bsd.pkg.mk"
