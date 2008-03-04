# $NetBSD: Makefile,v 1.31 2008/03/04 16:38:12 jlam Exp $

DISTNAME=	nawk-20050424
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://cm.bell-labs.com/who/bwk/
COMMENT=	Brian Kernighan's pattern-directed scanning and processing language

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CFLAGS+=	${CPPFLAGS}
MAKE_FLAGS+=	CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q}

NO_CHECKSUM=	yes
NO_MTREE=	yes
BUILD_TARGET=	a.out

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${DESTDIR}${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/nawk.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
