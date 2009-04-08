# $NetBSD: Makefile,v 1.18 2009/04/08 22:43:25 joerg Exp $

DISTNAME=	adjustkernel-1.7
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Generate a NetBSD kernel config

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes

USE_TOOLS+=	perl:run
REPLACE_PERL=	adjustkernel

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	${CP} ${FILESDIR}/adjustkernel ${WRKDIR}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/adjustkernel ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/adjustkernel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
