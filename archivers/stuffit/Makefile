# $NetBSD: Makefile,v 1.4 2002/03/31 04:58:25 uebayasi Exp $

DISTNAME=		stuffit520.611linux-i386
PKGNAME=		stuffit-5.2.0.611
CATEGORIES=		archivers
MASTER_SITES=		ftp://ftp.aladdinsys.com/pub/linux/StuffIt/ \
			ftp://ftp2.aladdinsys.com/pub/linux/StuffIt/
EXTRACT_SUFX=		.tgz

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.aladdinsys.com/expander
COMMENT=		Stuffit Archive Creator and Expander

DEPENDS+=		suse_base>=6:../../emulators/suse_base

WRKSRC=			${WRKDIR}
RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386

CHECK_SHLIBS=		NO
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/stuffit
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/stuffit/stuff
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/stuffit/unstuff
	${INSTALL_DATA} ${WRKSRC}/doc/stuff/* \
		${PREFIX}/share/doc/stuffit/stuff/
	${INSTALL_DATA} ${WRKSRC}/doc/unstuff/* \
		${PREFIX}/share/doc/stuffit/unstuff/

.include "../../mk/bsd.pkg.mk"
