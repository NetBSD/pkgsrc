# $NetBSD: Makefile,v 1.4 2002/12/09 00:19:46 rh Exp $
#

DISTNAME=	mailsync_4.3-2
PKGNAME=	mailsync-4.3.2
CATEGORIES=	mail
MASTER_SITES=	http://unc.dl.sourceforge.net/mailsync/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mailsync.sourceforge.net/
COMMENT=	Mailsync is a way of synchronizing a collection of mailboxes

DEPENDS+=	imap-uw-[0-9]*:../../mail/imap-uw

USE_GMAKE=	yes
ALL_TARGET=	default

WRKSRC=		${WRKDIR}/mailsync-4.3

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CFLAGS+=	-fno-operator-names
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mailsync ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mailsync
	${INSTALL_DATA} ${WRKSRC}/examples/mailsync				\
		${PREFIX}/share/examples/mailsync/dot.mailsync
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mailsync
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mailsync
	${INSTALL_DATA} ${WRKSRC}/WHATSNEW ${PREFIX}/share/doc/mailsync
	${INSTALL_MAN} ${WRKSRC}/mailsync.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
