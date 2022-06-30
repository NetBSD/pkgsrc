# $NetBSD: Makefile,v 1.23 2022/06/30 11:18:34 nia Exp $

DISTNAME=		newspipe.1.1.9
PKGNAME=		${DISTNAME:S/./-/}
PKGREVISION=		11
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=newspipe/}
EXTRACT_SUFX=		.zip

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://newspipe.sourceforge.net/
COMMENT=		Read RSS/Atom feeds as email messages

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
DEPENDS+=		${PYPKGPREFIX}-feedparser<6.0.0:../../textproc/py-feedparser5

WRKSRC=			${WRKDIR}

PYTHON_VERSIONED_DEPENDENCIES=	html2text
PYTHON_VERSIONS_ACCEPTED=	27

NO_BUILD=	yes
REPLACE_PYTHON=	*.py

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	do-configure
SUBST_FILES.bin=	newspipe.py newspipe
SUBST_VARS.bin=		LOCALBASE
SUBST_VARS.bin+=	PREFIX
SUBST_VARS.bin+=	PYTHONBIN

INSTALLATION_DIRS=	bin share/newspipe share/doc/newspipe
INSTALLATION_DIRS+=	share/examples/newspipe

do-install:
	cd ${WRKSRC};							\
	${INSTALL_SCRIPT} newspipe ${DESTDIR}${PREFIX}/bin;		\
	for f in cache.py newspipe.py opml.py; do			\
	${INSTALL_SCRIPT} $${f} ${DESTDIR}${PREFIX}/share/newspipe;	\
	done;								\
	for f in manual.html README; do					\
	${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/doc/newspipe;	\
	done;								\
	for f in newspipe.ini test.opml; do				\
	${INSTALL_DATA} $${f} ${DESTDIR}${PREFIX}/share/examples/newspipe; \
	done

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
