# $NetBSD: Makefile,v 1.6 2009/06/09 21:29:17 minskim Exp $

DISTNAME=	luatex-beta-0.40.2
PKGNAME=	kpathsea-5.0.0
CATEGORIES=	print
MASTER_SITES=	http://foundry.supelec.fr/gf/download/frsrelease/341/1275/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/kpathsea/
COMMENT=	Path searching library for TeX-related files

CONFLICTS+=	teTeX-bin<=3.0nb21
CONFLICTS+=	teTeX-texmf<=3.0nb5

EXTRACT_ELEMENTS=	${DISTNAME}/source/build-aux \
			${DISTNAME}/source/texk/kpathsea \
			${DISTNAME}/source/texk/make

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/source/texk/kpathsea

MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}

SUBST_CLASSES+=		texmfdir
SUBST_MESSAGE.texmfdir=	Setting texmf directories.
SUBST_STAGE.texmfdir=	pre-configure
SUBST_FILES.texmfdir=	texmf.cnf
SUBST_SED.texmfdir=	-e 's,@PREFIX@,${PREFIX},'
SUBST_SED.texmfdir+=	-e 's,@TEXMFLOCAL@,${TEXMFLOCAL},'
SUBST_SED.texmfdir+=	-e 's,@VARBASE@,${VARBASE},'
SUBST_SED.texmfdir+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'

PKG_SYSCONFSUBDIR=	texmf

BUILD_DEFS+=		VARBASE
TEXMFLOCAL=		${PREFIX}/share/texmf-local
FILES_SUBST+=		TEXMFLOCAL=${TEXMFLOCAL}

CONF_FILES=	${PREFIX}/share/texmf/web2c/texmf.cnf \
		${PKG_SYSCONFDIR}/texmf.cnf

OWN_DIRS+=		${TEXMFLOCAL} ${VARBASE}/lib/texmf
INSTALLATION_DIRS+=	share/texmf-dist

.include "../../mk/bsd.pkg.mk"
