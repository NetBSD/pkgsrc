# $NetBSD: Makefile,v 1.16 2004/04/24 22:46:11 jlam Exp $

DISTNAME=	imap-utils
PKGNAME=	imap-uw-utils-20020102
PKGREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.washington.edu/imap/
COMMENT=	UW IMAP mailbox utilities

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}
USE_BUILDLINK2=		# defined

SRCDIRS=	chkmail dmail icat ifrom imapcopy imapxfer \
		mbxcopy mbxcreat mbxcvt tmail

CFLAGS+=	-I${BUILDLINK_PREFIX.imap-uw}/include/c-client
LIBS+=		-lc-client -lssl -lcrypto

do-build:
	@for prog in ${SRCDIRS}; do					\
		${ECHO} "==> Building $${prog}";			\
		cd ${WRKSRC}/$${prog};					\
		${CC} ${CFLAGS} ${LDFLAGS} -o $${prog} $${prog}.c ${LIBS}; \
	done

do-install:
	@for prog in ${SRCDIRS}; do					\
		${ECHO} "==> Installing $${prog}";			\
		cd ${WRKSRC}/$${prog};					\
		${INSTALL_PROGRAM} $${prog} ${PREFIX}/bin;		\
		${INSTALL_MAN} $${prog}.1 ${PREFIX}/man/man1;		\
	done
	${LN} -sf imapcopy ${PREFIX}/bin/imapmove
	${LN} -sf mbxcopy ${PREFIX}/bin/mbxmove

.include "../../mail/imap-uw/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
