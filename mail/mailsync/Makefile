# $NetBSD: Makefile,v 1.14 2004/07/10 21:29:34 wiz Exp $
#

DISTNAME=	mailsync_4.4.4-1
PKGNAME=	mailsync-4.4.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailsync/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mailsync.sourceforge.net/
COMMENT=	Mailsync is a way of synchronizing a collection of mailboxes

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES+=	c c++
ALL_TARGET=	default

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD"
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

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/imap-uw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
