# $NetBSD: Makefile,v 1.6 2009/02/09 22:56:25 joerg Exp $
#

DISTNAME=		newspipe.1.1.9
PKGNAME=		${DISTNAME:S/./-/}
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=newspipe/}
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://newspipe.sourceforge.net/
COMMENT=		Read RSS/Atom feeds as email messages

WRKSRC=			${WRKDIR}

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=		${PYPKGPREFIX}-feedparser-[0-9]*:../../textproc/py-feedparser
DEPENDS+=		${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	*.py

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	do-configure
SUBST_FILES.bin=	newspipe.py newspipe
SUBST_SED.bin=		-e 's|@LOCALBASE@|${LOCALBASE}|g'
SUBST_SED.bin+=		-e 's|@PREFIX@|${PREFIX}|g'
SUBST_SED.bin+=		-e 's|@PYTHONBIN@|${PYTHONBIN}|g'

INSTALLATION_DIRS=	bin share/newspipe share/doc/newspipe
INSTALLATION_DIRS+=	share/examples/newspipe

do-install:
	cd ${WRKSRC};							\
	${INSTALL_SCRIPT} newspipe ${DESTDIR}${PREFIX}/bin;		\
	for f in cache.py newspipe.py opml.py; do			\
	${INSTALL_SCRIPT} $${f} ${DESTDIR}${PREFIX}/share/newspipe;	\
	done;								\
	for f in manual.html readme; do					\
	${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/newspipe;	\
	done;								\
	for f in newspipe.ini test.opml; do				\
	${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/examples/newspipe; \
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
