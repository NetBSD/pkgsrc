# $NetBSD: Makefile,v 1.1.1.1 2004/11/26 13:03:59 adam Exp $

DISTNAME=	mftrace-1.0.35
CATEGORIES=	fonts
MASTER_SITES=	http://www.xs4all.nl/~hanwen/mftrace/

MAINTAINER=	atamaniuk-pkgsrc@frobs.net
HOMEPAGE=	http://www.xs4all.nl/~hanwen/mftrace/
COMMENT=	Scalable Fonts for MetaFont

DEPENDS+=	autotrace>=0.31:../../graphics/autotrace
DEPENDS+=	pfaedit>=20030712:../../fonts/pfaedit
DEPENDS+=	t1utils>=1.27:../../fonts/t1utils
DEPENDS+=	teTeX>=2.0.2:../../print/teTeX

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
MAKEFILE=		GNUmakefile

PLIST_SUBST+=		PYSITELIB=${PYSITELIB}
PYTHON_VERSIONS_ACCEPTED=	20 21 21pth 22 22pth 23 23pth

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/tfm.py ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/afm.py ${PREFIX}/${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
