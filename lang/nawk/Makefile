# $NetBSD: Makefile,v 1.42 2014/10/09 14:06:38 wiz Exp $

DISTNAME=	nawk-20121220
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cs.princeton.edu/~bwk/btl.mirror/
COMMENT=	Brian Kernighan's pattern-directed scanning and processing language

BOOTSTRAP_PKG=	yes

CFLAGS+=	${CPPFLAGS} -DYYMAXDEPTH=300
MAKE_FLAGS+=	CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q}

BUILD_TARGET=	a.out

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/a.out ${DESTDIR}${PREFIX}/bin/nawk
	${INSTALL_MAN} ${WRKSRC}/nawk.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/nawk.1

.include "../../mk/bsd.pkg.mk"
