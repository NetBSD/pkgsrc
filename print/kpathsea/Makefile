# $NetBSD: Makefile,v 1.16 2012/07/10 22:32:13 minskim Exp $

DISTNAME=	texlive-20120701-source
PKGNAME=	kpathsea-6.1.0
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2012/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/kpathsea/
COMMENT=	Path searching library for TeX-related files
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	teTeX-bin<=3.0nb46
CONFLICTS+=	teTeX-texmf<=3.0nb5
CONFLICTS+=	texlive-tetex<2010

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/kpathsea

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/kpathsea

MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}

#
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

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	mktex.opt mktexdir mktexlsr mktexmf \
			mktexnam mktexnam.opt mktexpk mktextfm mktexupd
SUBST_SED.paths=	-e 's,@KPSEWHICH@,${PREFIX}/bin/kpsewhich,g'
SUBST_SED.paths+=	-e 's,@MKTEXMF@,${PREFIX}/bin/mktexmf,g'

PKG_SYSCONFSUBDIR=	texmf

BUILD_DEFS+=		VARBASE
TEXMFLOCAL=		${PREFIX}/share/texmf-local
FILES_SUBST+=		TEXMFLOCAL=${TEXMFLOCAL}

CONF_FILES=	${PREFIX}/share/texmf/web2c/texmf.cnf \
		${PKG_SYSCONFDIR}/texmf.cnf

OWN_DIRS+=		${TEXMFLOCAL} ${VARBASE}/lib/texmf
.for d in pk source tfm
OWN_DIRS_PERMS+=	${VARBASE}/lib/texmf/fonts/${d} \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 1777
.endfor
INSTALLATION_DIRS+=	share/texmf-dist

.include "../../mk/bsd.pkg.mk"
