# $NetBSD: Makefile,v 1.24 2023/12/30 21:30:47 zafer Exp $
#

DISTNAME=	splint-3.1.2.src
PKGNAME=	${DISTNAME:S/.src$//}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://splint.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs
LICENSE=	gnu-gpl-v2

# mv: rename .deps/cgrammar.TPo to .deps/cgrammar.Po: No such file or directory
MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c99
AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/manual.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/html/manual.htm ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/manual.html

.include "../../mk/bsd.pkg.mk"
