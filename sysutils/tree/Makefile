# $NetBSD: Makefile,v 1.12 2020/05/18 10:20:13 nia Exp $

DISTNAME=	tree-1.8.0
CATEGORIES=	sysutils
MASTER_SITES=	http://mama.indstate.edu/users/ice/tree/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mama.indstate.edu/users/ice/tree/
COMMENT=	Print a text or HTML tree diagram of a directory structure
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

CFLAGS.Linux+=	-DLINUX -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64

MAKE_FLAGS+=	prefix=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tree ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/tree.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
