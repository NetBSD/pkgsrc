# $NetBSD: Makefile,v 1.21 2019/11/03 10:55:22 rillig Exp $
#

DISTNAME=	splint-3.1.2.src
PKGNAME=	${DISTNAME:S/.src$//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.splint.org/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lclint.cs.virginia.edu/
COMMENT=	Statically check C programs
LICENSE=	gnu-gpl-v2

# mv: rename .deps/cgrammar.TPo to .deps/cgrammar.Po: No such file or directory
MAKE_JOBS_SAFE=		no

USE_TOOLS+=	gmake lex
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c99

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/splint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
