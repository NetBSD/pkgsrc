# $NetBSD: Makefile,v 1.3 2009/06/09 21:31:04 minskim Exp $

DISTNAME=	texlive-20080816-source
PKGNAME=	dvipsk-5.97
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.radicaleye.com/dvips.html
COMMENT=	DVI-to-PostScript translator

CONFLICTS+=	teTeX-bin<3.0nb24
CONFLICTS+=	teTeX-texmf<3.0nb9
BUILD_DEPENDS+=	texlive-tetex-[0-9]*:../../print/texlive-tetex
DEPENDS+=	tex-bin-dvipsk-[0-9]*:../../print/tex-bin-dvipsk

EXTRACT_ELEMENTS=	${DISTNAME}/texk/dvipsk \
			${DISTNAME}/texk/make \
			${DISTNAME}/texk/install.sh \
			${DISTNAME}/texk/mkinstalldirs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvipsk

FIND_PREFIX:=	TETEX_PREFIX=texlive-tetex BIN_DVIPSK_PREFIX=tex-bin-dvipsk
.include "../../mk/find-prefix.mk"

MAKE_ENV+=	KPATHSEA_PREFIX=${BUILDLINK_PREFIX.kpathsea}
MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q} \
		kpathsea_parent=${BUILDLINK_PREFIX.kpathsea}/include \
		kpathsea_srcdir=${BUILDLINK_PREFIX.kpathsea}/include/kpathsea \
		kpathsea=${BUILDLINK_PREFIX.kpathsea}/lib/libkpathsea.la

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			infodir=${DESTDIR}${PREFIX}/${PKGINFODIR} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dvips/config
CONF_FILES=	${PREFIX}/share/texmf-dist/dvips/config/config.ps \
		${PKG_SYSCONFDIR}/dvips/config/config.ps

BUILD_DEFS+=		PAPERSIZE
LOWER_PAPERSIZE_cmd=	${ECHO} ${PAPERSIZE} | ${TR} '[A-Z]' '[a-z]'
LOWER_PAPERSIZE=	${LOWER_PAPERSIZE_cmd:sh}

INSTALLATION_DIRS+=	share/texmf-dist/dvips/config

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"

post-build:
	${MKDIR} -p ${WRKSRC}/texmf/dvips/config
	${CP} ${BIN_DVIPSK_PREFIX}/share/texmf/dvips/config/config.ps \
		${WRKSRC}/texmf/dvips/config
	env TEXMFCONFIG=${BIN_DVIPSK_PREFIX}/share/texmf \
		TFC_TEXMFCONFIG=${WRKSRC}/texmf \
		configPsFile=${WRKSRC}/config.ps \
		${TETEX_PREFIX}/bin/texconfig dvips paper ${LOWER_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texmf/dvips/config/config.ps \
		${DESTDIR}${PREFIX}/share/texmf-dist/dvips/config

.include "../../mk/bsd.pkg.mk"
