# $NetBSD: Makefile,v 1.11 2002/11/15 00:04:08 jlam Exp $

PKGNAME=	courier-maildirmake-${BASE_VERS}
PKGREVISION?=	1
COMMENT=	Courier Maildir utilities

PERL5_REQD=	5.6.0
USE_PERL5=	build

REPLACE_PERL=		sysconftool

.include "../../mail/courier-auth/Makefile.common"

WRKSRC_FILES=		config.guess config.sub configure		\
			install-sh mkinstalldirs
WRKSRC_FILES+=		dbobj.h.in dbobj.config.in sysconftool
WRKSRC_SUBDIRS=		bdbobj gdbmobj numlib unicode rfc822
WRKSRC_SUBDIRS+=	maildir

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\//}

BUILD_DIRS=		${WRKSRC_SUBDIRS:S/^/${WRKSRC}\//}

.if defined(_STRIPFLAG_INSTALL) && !empty(_STRIPFLAG_INSTALL:M-s)
INSTALL_TARGET=		install-strip
.endif

CONF_FILES=		${EGDIR}/quotawarnmsg ${PKG_SYSCONFDIR}/quotawarnmsg

pre-configure: configure-init

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/quotawarnmsg ${EGDIR}/quotawarnmsg
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirquota.txt	\
		${DOCDIR}/README.maildirquota
	${INSTALL_DATA} ${WRKSRC}/maildir/README.sharedfolders.txt	\
		${DOCDIR}/README.sharedfolders

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
