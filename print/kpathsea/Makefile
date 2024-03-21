# $NetBSD: Makefile,v 1.37 2024/03/21 07:48:42 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	kpathsea-6.4.0
CATEGORIES=	print

HOMEPAGE=	https://ctan.org/pkg/kpathsea
COMMENT=	Path searching library for TeX-related files
LICENSE=	gnu-lgpl-v2.1

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/kpathsea

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/kpathsea

USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE=	kpathsea.pc.in
INFO_FILES=		yes

MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}

DEPENDS+=	mktexlsr-[0-9]*:../../print/mktexlsr

# A double-slash (//) in the kpathsea paths has a special
# interpretation, it will cause kpathsea to consider all
# subdirectories recursively at that point in the path.  Normally
# double-slashes and trailing slashes will not be present in these
# variables, but if they are there the resulting behaviour is so
# unexpected, expensive, and difficult to diagnose that it is worth
# going to extra effort to clean them out here.
#
SUBST_CLASSES+=		texmfdir
SUBST_MESSAGE.texmfdir=	Setting texmf directories.
SUBST_STAGE.texmfdir=	pre-configure
SUBST_FILES.texmfdir=	texmf.cnf
SUBST_SED.texmfdir=	-e 's,@PREFIX@,${PREFIX:C;///*;/;g:C;/$;;},'
SUBST_SED.texmfdir+=	-e 's,@TEXMFLOCAL@,${TEXMFLOCAL:C;///*;/;g:C;/$;;},'
SUBST_SED.texmfdir+=	-e 's,@VARBASE@,${VARBASE:C;///*;/;g:C;/$;;},'
SUBST_SED.texmfdir+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR:C;///*;/;g:C;/$;;},'

PKG_SYSCONFSUBDIR=	texmf

BUILD_DEFS+=		VARBASE
TEXMFLOCAL=		${PREFIX}/share/texmf-local
FILES_SUBST+=		TEXMFLOCAL=${TEXMFLOCAL}

CONF_FILES=	${PREFIX}/share/texmf-dist/web2c/texmf.cnf \
		${PKG_SYSCONFDIR}/texmf.cnf

OWN_DIRS+=		${TEXMFLOCAL} ${VARBASE}/lib/texmf
.for d in pk source tfm
OWN_DIRS_PERMS+=	${VARBASE}/lib/texmf/fonts/${d} \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777
.endfor
INSTALLATION_DIRS+=	share/texmf-dist

.include "../../mk/bsd.pkg.mk"
