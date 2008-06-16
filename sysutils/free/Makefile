# $NetBSD: Makefile,v 1.11 2008/06/16 15:41:44 joerg Exp $
#

DISTNAME=		free-1.0
CATEGORIES=		sysutils
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Displays memory usage

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=	IPV6_READY

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${FILESDIR}/free ${DESTDIR}${PREFIX}/bin/free
	${INSTALL_MAN} ${FILESDIR}/free.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/free.1

.include "../../mk/bsd.pkg.mk"
