# $NetBSD: Makefile,v 1.1.1.1 2001/01/25 23:00:53 jlam Exp $

DISTNAME=	imap-utils
PKGNAME=	imap-uw-utils-20001220
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.washington.edu/imap/

DEPENDS+=	imap-uw-2000*:../../mail/imap-uw

DIST_SUBDIR=	${PKGNAME}
NO_WRKSUBDIR=	# defined
NO_CONFIGURE=	# defined

SRCDIRS=	chkmail dmail icat ifrom imapcopy imapxfer \
		mbxcopy mbxcreat mbxcvt tmail

CFLAGS+=	-I${LOCALBASE}/include/c-client
LIBS+=		-limapuw -lssl -lcrypto

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

.include "../../mk/bsd.pkg.mk"
