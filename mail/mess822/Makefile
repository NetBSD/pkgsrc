# $NetBSD: Makefile,v 1.1.1.1 2004/07/26 23:26:27 schmonz Exp $
#

DISTNAME=		mess822-0.58
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/mess822.html
COMMENT=		Library for parsing Internet mail messages

DEPENDS+=		{qmail>=1.03nb7,netqmail>=1.05}:../../mail/qmail

# We change conf-home from the default "/usr/local" and don't
# provide compatibilbity symlinks. We also patch hier.c to respect
# PKG_SYSCONFDIR and set reasonable modes on directories under
# ${PREFIX}.
RESTRICTED=		"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes

EGDIR=			${PREFIX}/share/examples/mess822
CFLAGS+=		-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"
USE_PKGINSTALL=		yes
MAKE_DIRS+=		${PKG_SYSCONFDIR}
SUPPORT_FILES+=		${EGDIR}/leapsecs.dat ${PKG_SYSCONFDIR}/leapsecs.dat

ALL_TARGET=		it install instcheck
INSTALL_TARGET=		setup check

INSTALLATION_DIRS=	bin include lib man man/cat1 man/cat3 man/cat5 man/cat8
INSTALLATION_DIRS+=	man/man1 man/man3 man/man5 man/man8 share/examples/mess822

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX} > ${WRKSRC}/conf-home
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

.include "../../mk/bsd.pkg.mk"
