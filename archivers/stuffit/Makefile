# $NetBSD: Makefile,v 1.25 2006/05/22 22:22:02 jlam Exp $

DISTNAME=		stuffit520.611linux-i386
PKGNAME=		stuffit-5.2.0.611
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		http://www.allume.com/downloads/files/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.stuffit.com/unix/stuffit/
COMMENT=		Stuffit Archive Creator and Expander

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_base>=6:../../emulators/${SUSE_DIR_PREFIX}_base
.endif

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
NO_BUILD=		yes

INSTALLATION_DIRS=	bin man/man1

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
