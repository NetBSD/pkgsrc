# $NetBSD: Makefile,v 1.5 2023/12/29 01:17:06 zafer Exp $
#

DISTNAME=		cvsclone
PKGNAME=		cvsclone-0.00
CATEGORIES=		devel scm
MASTER_SITES=		https://www.samba.org/ftp/tridge/rtc/
EXTRACT_SUFX=		.l

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://samba.org/ftp/tridge/rtc/
COMMENT=		Clone a CVS repository using the :pserver: access method

DIST_SUBDIR=		${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin
WRKSRC=			${WRKDIR}
USE_TOOLS+=		lex

LDFLAGS.SunOS+=		-lsocket -lnsl

do-build:
	cd ${WRKSRC} && \
	${LEX} cvsclone.l && \
	${CC} ${CFLAGS} lex.yy.c ${LDFLAGS} -o cvsclone
	cd ${WRKSRC} && ${HEAD} -88 cvsclone.l > README.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsclone ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/cvsclone
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/cvsclone

.include "../../mk/bsd.pkg.mk"
