# $NetBSD: Makefile,v 1.4 2002/01/22 22:06:06 jlam Exp $

PKGNAME=	courier-maildirmake-${BASE_VERS}
PKGREVISION?=	# empty
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

.if !defined(STRIPFLAG) || empty(STRIPFLAG:M-s)
INSTALL_TARGET=		install-strip
.else
INSTALL_TARGET=		install
.endif

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
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/maildir/README.maildirquota.txt	\
		${DOCDIR}/README.maildirquota
	${INSTALL_DATA} ${WRKSRC}/maildir/README.sharedfolders.txt	\
		${DOCDIR}/README.sharedfolders

.include "../../mk/bsd.pkg.mk"
