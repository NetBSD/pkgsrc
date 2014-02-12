# $NetBSD: Makefile,v 1.32 2014/02/12 23:18:08 tron Exp $

DISTNAME=	imap-utils
PKGNAME=	imap-uw-utils-20050108
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.washington.edu/imap/
COMMENT=	UW IMAP mailbox utilities

DIST_SUBDIR=	${PKGNAME_NOREV}

BUILDLINK_API_DEPENDS.imap-uw+=	imap-uw>=2004c1nb1

SRCDIRS=	icat ifrom

CFLAGS+=	-I${BUILDLINK_PREFIX.imap-uw}/include/c-client
LIBS+=		-lc-client -lssl -lcrypto

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

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
		${INSTALL_PROGRAM} $${prog} ${DESTDIR}${PREFIX}/bin;	\
		${INSTALL_MAN} $${prog}.1				\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;		\
	done

.include "../../mail/imap-uw/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
