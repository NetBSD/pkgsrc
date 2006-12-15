# $NetBSD: Makefile,v 1.27 2006/12/15 14:34:18 wiz Exp $

DISTNAME=		stuffit520.611linux-i386
PKGNAME=		stuffit-5.2.0.611
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		http://www.allume.com/downloads/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
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

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/stuffit/stuff share/doc/stuffit/unstuff

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/stuff/* \
		${PREFIX}/share/doc/stuffit/stuff/
	${INSTALL_DATA} ${WRKSRC}/doc/unstuff/* \
		${PREFIX}/share/doc/stuffit/unstuff/

.include "../../mk/bsd.pkg.mk"
