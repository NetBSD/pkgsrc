# $NetBSD: Makefile,v 1.4.2.1 2010/04/20 21:26:19 tron Exp $

DISTNAME=	texlive-20091011-source
PKGNAME=	dvipsk-5.98
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.radicaleye.com/dvips.html
COMMENT=	DVI-to-PostScript translator

CONFLICTS+=	teTeX-bin<3.0nb24
CONFLICTS+=	teTeX-texmf<3.0nb9
BUILD_DEPENDS+=	texlive-tetex-[0-9]*:../../print/texlive-tetex
DEPENDS+=	tex-dvips>=2009.16376:../../print/tex-dvips

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/dvipsk

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvipsk

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib

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
	${CP} ${LOCALBASE}/share/texmf/dvips/config/config.ps \
		${WRKSRC}/texmf/dvips/config
	env TEXMFCONFIG=${LOCALBASE}/share/texmf \
		TFC_TEXMFCONFIG=${WRKSRC}/texmf \
		configPsFile=${WRKSRC}/config.ps \
		${LOCALBASE}/bin/texconfig dvips paper ${LOWER_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texmf/dvips/config/config.ps \
		${DESTDIR}${PREFIX}/share/texmf-dist/dvips/config

.include "../../mk/bsd.pkg.mk"
