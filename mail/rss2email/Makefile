# $NetBSD: Makefile,v 1.28 2012/03/15 11:53:30 obache Exp $
#

DISTNAME=		rss2email-2.71
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://www.allthingsrss.com/rss2email/
COMMENT=		Get RSS feeds emailed to you
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	*.py

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	do-configure
SUBST_FILES.bin=	rss2email.py r2e
SUBST_SED.bin=		-e 's|@LOCALBASE@|${LOCALBASE}|g'
SUBST_SED.bin+=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.bin+=		-e 's|@PYTHONBIN@|${PYTHONBIN}|g'

SUBST_CLASSES+=		crlf
SUBST_STAGE.crlf=	post-extract
SUBST_FILES.crlf=	config.py.example
SUBST_SED.crlf=		-e 's|||g'

SHAREDIR=		${PREFIX}/share/rss2email
EGDIR=			${PREFIX}/share/examples/rss2email
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	cp ${FILESDIR}/r2e.1 ${WRKSRC}

do-install:
	set -e; cd ${WRKSRC};						\
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${SHAREDIR};			\
	${INSTALL_SCRIPT} rss2email.py ${DESTDIR}${SHAREDIR};		\
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR};				\
	${INSTALL_DATA} config.py.example ${DESTDIR}${EGDIR}/config.py;	\
	${INSTALL_MAN} r2e.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;	\
	${INSTALL_SCRIPT} r2e ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
