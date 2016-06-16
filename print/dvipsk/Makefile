# $NetBSD: Makefile,v 1.15 2016/06/16 04:06:19 markd Exp $

DISTNAME=	texlive-20160523-source
PKGNAME=	dvipsk-5.996
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2016/
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
USE_TOOLS+=	pkg-config
CONFIGURE_DIRS=	texk/dvipsk

CONFIGURE_ARGS+=	--with-system-kpathsea

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

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"

post-build:
	${MKDIR} -p ${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config
	${CP} ${LOCALBASE}/share/texmf-dist/dvips/config/config.ps \
		${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config
	env TEXMFCONFIG=${LOCALBASE}/share/texmf-dist \
		TFC_TEXMFCONFIG=${WRKSRC}/texk/dvipsk/texmf \
		configPsFile=${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config/config.ps \
		${LOCALBASE}/bin/texconfig dvips paper ${LOWER_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config/config.ps \
		${DESTDIR}${PREFIX}/share/examples/dvipsk

.include "../../mk/bsd.pkg.mk"
