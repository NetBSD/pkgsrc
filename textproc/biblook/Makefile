# $NetBSD: Makefile,v 1.5 2004/01/20 12:26:49 agc Exp $
#

DISTNAME=	biblook
PKGNAME=	${DISTNAME}-2.9
CATEGORIES=	textproc
MASTER_SITES=	http://compgeom.cs.uiuc.edu/~jeffe/files/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://compgeom.cs.uiuc.edu/~jeffe/biblook.html
COMMENT=	Indexing and searching tools for BibTeX bibliography databases

.include "../../mk/bsd.prefs.mk"

WRKSRC=		${WRKDIR}
MAKE_FLAGS=     CC="${CC}"

# override definitions in the package's Makefile via command line
.if ${OPSYS} == "NetBSD"
MAKE_FLAGS+=    OPT="${CFLAGS} -Dunix"
MAKE_FLAGS+=    DEF_H_FILES="-DHAVE_STDLIB_H -DHAVE_NETINET_IN_H"
MAKE_FLAGS+=    DEF_MORE="-DMOREPATH=\\\"/usr/bin/more\\\" -DMORE=\\\"more\\\""
.endif

.include "../../mk/bsd.pkg.mk"
