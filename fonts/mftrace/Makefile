# $NetBSD: Makefile,v 1.24 2012/10/03 18:28:27 asau Exp $

DISTNAME=	mftrace-1.2.15
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	http://lilypond.org/download/sources/mftrace/

MAINTAINER=	atamaniuk-pkgsrc@frobs.net
HOMEPAGE=	http://lilypond.org/mftrace/
COMMENT=	Scalable Fonts for MetaFont
LICENSE=	mit AND gnu-gpl-v2

DEPENDS+=	autotrace>=0.31:../../graphics/autotrace
DEPENDS+=	potrace>=1.5:../../graphics/potrace
DEPENDS+=	fontforge>=20041115:../../fonts/fontforge
DEPENDS+=	t1utils>=1.27:../../fonts/t1utils

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}
MAKE_FILE=		GNUmakefile

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PYSITELIB}

post-build:
	cd ${WRKSRC} && ${PYTHONBIN} ${PREFIX}/${PYLIB}/py_compile.py afm.py
	cd ${WRKSRC} && ${PYTHONBIN} ${PREFIX}/${PYLIB}/py_compile.py tfm.py

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gf2pbm ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mftrace ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mftrace.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/afm.py ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/afm.pyc ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/tfm.py ${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/tfm.pyc ${DESTDIR}${PREFIX}/${PYSITELIB}

.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
