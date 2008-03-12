# $NetBSD: Makefile,v 1.1.1.1 2008/03/12 10:16:05 wiz Exp $
#

DISTNAME=		cvsclone
PKGNAME=		cvsclone-0.00
CATEGORIES=		devel scm
MASTER_SITES=		http://samba.org/ftp/tridge/rtc/
EXTRACT_SUFX=		.l

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://samba.org/ftp/tridge/rtc/
COMMENT=		Clone a CVS repository using the :pserver: access method

DIST_SUBDIR=		${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin
WRKSRC=			${WRKDIR}
USE_TOOLS+=		lex

do-build:
	cd ${WRKSRC} && \
	${LEX} cvsclone.l && \
	${CC} ${CFLAGS} lex.yy.c -o cvsclone
	cd ${WRKSRC} && ${HEAD} -88 cvsclone.l > README.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsclone ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cvsclone
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/cvsclone

.include "../../mk/bsd.pkg.mk"
