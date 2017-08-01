# $NetBSD: Makefile,v 1.20 2017/08/01 16:47:40 wiz Exp $
#

DISTNAME=	dync-1.1
PKGREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.westley.demon.co.uk/src/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	C language awk-like utility

GNU_CONFIGURE=		yes
BUILD_TARGET=		tst
USE_TOOLS+=		file_cmd
CONFIGURE_ENV+=		FILE_CMD=${TOOLS_FILE_CMD:Q}
CONFIGURE_ENV+=		ac_cv_path_LDCONFIG=${TOOLS_LDCONFIG:Q}

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dync ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dync.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
