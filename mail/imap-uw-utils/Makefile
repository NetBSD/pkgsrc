# $NetBSD: Makefile,v 1.7 2002/09/02 14:38:23 wiz Exp $

DISTNAME=	imap-utils
PKGNAME=	imap-uw-utils-20020102
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.washington.edu/imap/
COMMENT=	UW IMAP mailbox utilities

DIST_SUBDIR=		${PKGNAME}
WRKSRC=			${WRKDIR}
USE_BUILDLINK_ONLY=	# defined

SRCDIRS=	chkmail dmail icat ifrom imapcopy imapxfer \
		mbxcopy mbxcreat mbxcvt tmail

CFLAGS+=	-I${BUILDLINK_DIR}/include/c-client
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

.include "../../mail/imap-uw/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
