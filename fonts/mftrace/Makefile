# $NetBSD: Makefile,v 1.15 2006/09/09 02:42:00 obache Exp $

DISTNAME=	mftrace-1.1.18
CATEGORIES=	fonts
MASTER_SITES=	http://www.xs4all.nl/~hanwen/mftrace/

MAINTAINER=	atamaniuk-pkgsrc@frobs.net
HOMEPAGE=	http://www.xs4all.nl/~hanwen/mftrace/
COMMENT=	Scalable Fonts for MetaFont

DEPENDS+=	autotrace>=0.31:../../graphics/autotrace
DEPENDS+=	potrace>=1.5:../../graphics/potrace
DEPENDS+=	fontforge>=20041115:../../fonts/fontforge
DEPENDS+=	t1utils>=1.27:../../fonts/t1utils

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
MAKE_FILE=		GNUmakefile

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}
PYTHON_VERSIONS_ACCEPTED=	24 23 22 21

INSTALLATION_DIRS=	bin man/man1 ${PYSITELIB}

post-build:
	cd ${WRKSRC} && ${PYTHONBIN} ${PREFIX}/${PYLIB}/py_compile.py afm.py
	cd ${WRKSRC} && ${PYTHONBIN} ${PREFIX}/${PYLIB}/py_compile.py tfm.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/afm.py ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/afm.pyc ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/tfm.py ${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/tfm.pyc ${PREFIX}/${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
