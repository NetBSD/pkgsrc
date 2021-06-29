# $NetBSD: Makefile,v 1.1 2021/06/29 14:28:12 hauke Exp $

DISTNAME=	SMathStudioDesktop.${PKGVERSION_NOREV:S/./_/g}.Mono
PKGNAME=	smath-studio-${PKGVER}
PKGVER=		0.99.7822
CATEGORIES=	math
MASTER_SITES=	https://smath.com/file/oVRx7/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://smath.com/
DOWNLOAD=	https://en.smath.com/view/SMathStudio/summary
DOWNLOAD_NAME=	SMath Studio Desktop for Mono
COMMENT=	Tiny, powerful, free mathematical program with WYSIWYG editor

LICENSE=		smath-license
RESTRICTED=		Redistribution of repackaged binaries not permitted
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

EXTRACT_DIR=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	# none
NO_BUILD=	YES

DEPENDS+=	mono-[0-9]*:../../lang/mono
DEPENDS+=	libgdiplus-[0-9]*:../../graphics/libgdiplus

FETCH_MESSAGE+=	" The file ${DISTNAME}${EXTRACT_SUFX} containing ${DOWNLOAD_NAME}"
FETCH_MESSAGE+=	""
FETCH_MESSAGE+=	" must be fetched into:"
FETCH_MESSAGE+=	"       ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}"
FETCH_MESSAGE+=	" from:"
FETCH_MESSAGE+=	"       ${DOWNLOAD}"

USE_TOOLS+=	pax

EGDIR=			share/examples/smath-studio
DOCDIR=			share/doc/smath-studio
SMATH_DIR=		libexec/smath-studio
INSTALLATION_DIRS=	bin ${EGDIR} ${DOCDIR} ${SMATH_DIR}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	smath-studio.sh
SUBST_VARS.paths=	PREFIX SMATH_DIR

SUBST_CLASSES+=		switch
SUBST_STAGE.switch=	pre-configure
SUBST_MESSAGE.switch=	Disabling runtime download.
SUBST_FILES.switch=	SMathStudio_Desktop.exe.config
SUBST_SED.switch=	-E -e 's,(loadFromRemoteSources enabled)="true",\1="false",'

post-extract:
	find ${WRKSRC} -type f -exec chmod -x {} \;
	cp ${FILESDIR}/smath-studio.sh ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/smath-studio.sh \
		${DESTDIR}${PREFIX}/bin/smath-studio
	cd ${WRKSRC} && pax -rw EULA book ${DESTDIR}${PREFIX}/${DOCDIR}/
.for dd in EULA book
	cd ${WRKSRC} && rm -r ${dd} && \
		ln -s ${PREFIX}/${DOCDIR}/${dd} \
		${DESTDIR}${PREFIX}/${SMATH_DIR}/${dd}
.endfor
	cd ${WRKSRC} && pax -rw examples ${DESTDIR}${PREFIX}/${EGDIR}/
	cd ${WRKSRC} && rm -r examples && \
		ln -s ${PREFIX}/${EGDIR}/examples \
		${DESTDIR}${PREFIX}/${SMATH_DIR}/examples
.for dd in SMath.*.dll SMathStudio_Desktop.exe entries lang \
	plugins representation snippets
	cd ${WRKSRC} && pax -rw ${dd} ${DESTDIR}${PREFIX}/${SMATH_DIR}/
.endfor

.include "../../mk/bsd.pkg.mk"
