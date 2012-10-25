# $NetBSD: Makefile,v 1.15 2012/10/25 06:55:42 asau Exp $
#

DISTNAME=	biblook
PKGNAME=	${DISTNAME}-2.9
CATEGORIES=	textproc
MASTER_SITES=	http://compgeom.cs.uiuc.edu/~jeffe/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compgeom.cs.uiuc.edu/~jeffe/biblook.html
COMMENT=	Indexing and searching tools for BibTeX bibliography databases

WRKSRC=		${WRKDIR}
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	CC=${CC:Q}

# override definitions in the package's Makefile via command line
MAKE_FLAGS+=	OPT="${CFLAGS} -Dunix"
MAKE_FLAGS+=	DEF_H_FILES="-DHAVE_STDLIB_H -DHAVE_NETINET_IN_H"
MAKE_FLAGS+=	DEF_MORE='-DMOREPATH="\"/usr/bin/more\"" -DMORE="\"more\""'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
