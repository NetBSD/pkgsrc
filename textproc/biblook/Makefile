# $NetBSD: Makefile,v 1.6 2004/05/23 23:28:29 danw Exp $
#

DISTNAME=	biblook
PKGNAME=	${DISTNAME}-2.9
CATEGORIES=	textproc
MASTER_SITES=	http://compgeom.cs.uiuc.edu/~jeffe/files/

MAINTAINER=	seb@pbox.org
HOMEPAGE=	http://compgeom.cs.uiuc.edu/~jeffe/biblook.html
COMMENT=	Indexing and searching tools for BibTeX bibliography databases

WRKSRC=		${WRKDIR}
MAKE_FLAGS=     CC="${CC}"

# override definitions in the package's Makefile via command line
MAKE_FLAGS+=    OPT="${CFLAGS} -Dunix"
MAKE_FLAGS+=    DEF_H_FILES="-DHAVE_STDLIB_H -DHAVE_NETINET_IN_H"
MAKE_FLAGS+=    DEF_MORE="-DMOREPATH=\\\"/usr/bin/more\\\" -DMORE=\\\"more\\\""

.include "../../mk/bsd.pkg.mk"
