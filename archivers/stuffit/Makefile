# $NetBSD: Makefile,v 1.12 2003/12/13 20:14:26 ben Exp $

DISTNAME=		stuffit520.611linux-i386
PKGNAME=		stuffit-5.2.0.611
WRKSRC=			${WRKDIR}
CATEGORIES=		archivers
MASTER_SITES=		ftp://ftp.aladdinsys.com/pub/linux/StuffIt/ \
			ftp://ftp2.aladdinsys.com/pub/linux/StuffIt/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		http://www.aladdinsys.com/expander/
COMMENT=		Stuffit Archive Creator and Expander

DEPENDS+=		suse_base>=6:../../emulators/${SUSE_DIR_PREFIX}_base

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386

CHECK_SHLIBS=		NO
NO_CONFIGURE=		# defined
NO_BUILD=		# defined
USE_BUILDLINK2=		# defined

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

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
