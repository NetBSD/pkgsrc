# $NetBSD: Makefile,v 1.6 2002/02/03 13:38:39 jlam Exp $

PKGNAME=	courier-maildirmake-${BASE_VERS}
PKGREVISION?=	1
COMMENT=	Courier Maildir utilities

PERL5_REQD=	5.6.0
BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

USE_BUILDLINK_ONLY=	yes
REPLACE_PERL=		sysconftool

.include "../../mail/courier-auth/Makefile.common"

WRKSRC_FILES=		config.guess config.sub configure		\
			install-sh mkinstalldirs
WRKSRC_FILES+=		dbobj.h.in dbobj.config.in sysconftool
WRKSRC_SUBDIRS=		bdbobj gdbmobj numlib unicode rfc822
WRKSRC_SUBDIRS+=	maildir

EXTRACT_ELEMENTS=	${WRKSRC_FILES:S/^/${DISTNAME}\//}
EXTRACT_ELEMENTS+=	${WRKSRC_SUBDIRS:S/^/${DISTNAME}\//}

.if defined(STRIPFLAG) && !empty(STRIPFLAG:M-s)
INSTALL_TARGET=		install-strip
.endif

CONF_FILES=		${EGDIR}/quotawarnmsg ${PKG_SYSCONFDIR}/quotawarnmsg

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/DEINSTALL

pre-configure: configure-init

do-build:
.for DIR in ${WRKSRC_SUBDIRS}
	@cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${ALL_TARGET}
.endfor

do-install:
.for DIR in ${WRKSRC_SUBDIRS}
	@cd ${WRKSRC}/${DIR} && ${SETENV} ${MAKE_ENV}			\
		${MAKE_PROGRAM} ${INSTALL_TARGET}
.endfor

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/quotawarnmsg ${EGDIR}/quotawarnmsg
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirquota.txt	\
		${DOCDIR}/README.maildirquota
	${INSTALL_DATA} ${WRKSRC}/maildir/README.sharedfolders.txt	\
		${DOCDIR}/README.sharedfolders

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
