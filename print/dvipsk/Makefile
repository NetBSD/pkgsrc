# $NetBSD: Makefile,v 1.31 2024/03/21 08:19:19 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dvipsk-2024.1
CATEGORIES=	print

HOMEPAGE=	http://www.radicaleye.com/dvips.html
COMMENT=	DVI-to-PostScript translator

#TOOL_DEPENDS+=	tex-texlive-scripts-[0-9]*:../../print/tex-texlive-scripts
DEPENDS+=	tex-dvips>=2013:../../print/tex-dvips

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/dvipsk

INFO_FILES=	yes

# texk/dvipsk/squeeze/configure doesn't know --with-system-kpathsea
GNU_CONFIGURE_STRICT=	no
CONFIGURE_DIRS=		texk/dvipsk
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

post-build:
	${MKDIR} ${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config
	${CP} ${LOCALBASE}/share/texmf-dist/dvips/config/config.ps \
		${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config
#	${SETENV} TEXMFCONFIG=${LOCALBASE}/share/texmf-dist \
#		TFC_TEXMFCONFIG=${WRKSRC}/texk/dvipsk/texmf \
#		configPsFile=${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config/config.ps \
#		${LOCALBASE}/bin/texconfig dvips paper ${LOWER_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texk/dvipsk/texmf-dist/dvips/config/config.ps \
		${DESTDIR}${PREFIX}/share/examples/dvipsk
	${RM} -rf ${DESTDIR}${PREFIX}/share/texmf-dist/fonts

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
