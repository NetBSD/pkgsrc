# $NetBSD: Makefile,v 1.11 2013/11/17 16:54:41 minskim Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	dvipsk-5.993
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.radicaleye.com/dvips.html
COMMENT=	DVI-to-PostScript translator

CONFLICTS+=	teTeX-bin<3.0nb24
CONFLICTS+=	teTeX-texmf<3.0nb9
BUILD_DEPENDS+=	tex-texconfig-[0-9]*:../../print/tex-texconfig
DEPENDS+=	tex-dvips>=2013:../../print/tex-dvips

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/dvipsk

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
CONFIGURE_DIRS=	texk/dvipsk

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dvips/config
CONF_FILES=	${PREFIX}/share/examples/dvipsk/config.ps \
		${PKG_SYSCONFDIR}/dvips/config/config.ps

BUILD_DEFS+=		PAPERSIZE
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}

INSTALLATION_DIRS+=	share/examples/dvipsk

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

FIND_PREFIX:=	TEX_DVIPS_PREFIX=tex-dvips \
		TEXCONFIG_PREFIX=tex-texconfig
.include "../../mk/find-prefix.mk"

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"

post-build:
	${MKDIR} -p ${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config
	${CP} ${TEX_DVIPS_PREFIX}/share/texmf-dist/dvips/config/config.ps \
		${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config
	env TEXMFCONFIG=${TEX_DVIPS_PREFIX}/share/texmf-dist \
		TFC_TEXMFCONFIG=${WRKSRC}/texk/dvipsk/texmf \
		configPsFile=${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config/config.ps \
		${TEXCONFIG_PREFIX}/bin/texconfig dvips paper ${LOWER_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config/config.ps \
		${DESTDIR}${PREFIX}/share/examples/dvipsk

.include "../../mk/bsd.pkg.mk"
