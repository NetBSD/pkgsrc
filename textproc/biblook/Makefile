# $NetBSD: Makefile,v 1.3 2003/04/21 14:22:57 jschauma Exp $
#

DISTNAME=	biblook
PKGNAME=	${DISTNAME}-2.9
WRKSRC=		${WRKDIR}
CATEGORIES=	textproc
MASTER_SITES=	http://compgeom.cs.uiuc.edu/~jeffe/files/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://compgeom.cs.uiuc.edu/~jeffe/biblook.html
COMMENT=	indexing and searching tools for BibTeX bibliography databases

.include "../../mk/bsd.prefs.mk"

MAKE_FLAGS=     CC="${CC}"

# override definitions in the package's Makefile via command line
.if ${OPSYS} == "NetBSD"
MAKE_FLAGS+=    OPT="${CFLAGS} -Dunix"
MAKE_FLAGS+=    DEF_H_FILES="-DHAVE_STDLIB_H -DHAVE_NETINET_IN_H"
MAKE_FLAGS+=    DEF_MORE="-DMOREPATH=\\\"/usr/bin/more\\\" -DMORE=\\\"more\\\""
.endif

.include "../../mk/bsd.pkg.mk"
