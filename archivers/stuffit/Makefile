# $NetBSD: Makefile,v 1.29 2007/10/31 21:50:49 gdt Exp $

DISTNAME=		stuffit520.611linux-i386
PKGNAME=		stuffit-5.2.0.611
PKGREVISION=		1
CATEGORIES=		archivers
MASTER_SITES=		http://www.allume.com/downloads/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.stuffit.com/unix/stuffit/
COMMENT=		Stuffit Archive Creator and Expander

LICENSE=		generic-nonlicense
RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

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
