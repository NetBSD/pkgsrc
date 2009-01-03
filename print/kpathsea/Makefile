# $NetBSD: Makefile,v 1.1.1.1 2009/01/03 22:12:42 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	kpathsea-3.5.7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/kpathsea/
COMMENT=	Path searching library for TeX-related files

CONFLICTS+=	teTeX-bin-[0-9]*
CONFLICTS+=	teTeX-texmf-[0-9]*

EXTRACT_ELEMENTS=	${DISTNAME}/texk/kpathsea \
			${DISTNAME}/texk/make \
			${DISTNAME}/texk/config.guess \
			${DISTNAME}/texk/config.sub \
			${DISTNAME}/texk/install.sh \
			${DISTNAME}/texk/mkinstalldirs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/kpathsea

MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}

SUBST_CLASSES+=		texmfdir
SUBST_MESSAGE.texmfdir=	Setting texmf directories.
SUBST_STAGE.texmfdir=	pre-configure
SUBST_FILES.texmfdir=	texmf.cnf
SUBST_SED.texmfdir=	-e 's,@TEXMFLOCAL@,${TEXMFLOCAL},'
SUBST_SED.texmfdir+=	-e 's,@VARBASE@,${VARBASE},'
SUBST_SED.texmfdir+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},'

PKG_SYSCONFSUBDIR=	texmf

BUILD_DEFS+=		VARBASE
TEXMFLOCAL=		${PREFIX}/share/texmf-local
FILES_SUBST+=		TEXMFLOCAL=${TEXMFLOCAL}

CONF_FILES=	${PREFIX}/share/texmf/web2c/texmf.cnf \
		${PKG_SYSCONFDIR}/texmf.cnf

OWN_DIRS+=		${TEXMFLOCAL} ${VARBASE}/lib/texmf
INSTALLATION_DIRS+=	share/doc/texmf share/texmf-dist

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.pkg.mk"
