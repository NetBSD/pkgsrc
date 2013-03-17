# $NetBSD: Makefile,v 1.6 2013/03/17 08:42:55 obache Exp $

DISTNAME=	ghostscript-cidfonts-ryumin-${GS_VERSION}
DISTFILES=	# empty
PKGREVISION=	4
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enable Ryumin-Light and GothicBBB for ghostscript
LICENSE=	generic-nonlicense

.include	"../../print/ghostscript-gpl/Makefile.common"

GS_RESOURCEDIR=		share/ghostscript/${PKGVERSION}/Resource
WRKSRC=			${WRKDIR}/gcr
INSTALLATION_DIRS+=	${GS_RESOURCEDIR}/Font
INSTALLATION_DIRS+=	${GS_RESOURCEDIR}/Init

DEPENDS+=	ghostscript-gpl>=9.05:../../print/ghostscript-gpl
DEPENDS+=	ghostscript-cidfonts>=20000901nb3:../../fonts/ghostscript-cidfonts
BUILD_DEFS+=	GS_CIDFMAP
# used in options.mk to switch adobe or ttf
SUBST_VARS=	GCR_INSTALL_TYPE

.include "options.mk"

.if !empty(GS_CIDFMAP)
SUBST_CLASSES+=		ttf_path
SUBST_STAGE.ttf_path=	post-build
SUBST_MESSAGE.ttf_path=Fixing ttf install directory in cidfmap
SUBST_FILES.ttf_path=	${GS_CIDFMAP}
SUBST_SED.ttf_path=	-e 's|%%PREFIX%%|${PREFIX}|'
.endif

# To edit %%PREFIX%% in cidfmap before installation by SUBST,
do-build:
.if !empty(GS_CIDFMAP)
	${MKDIR}		  ${WRKSRC}
	${CP} files/${GS_CIDFMAP} ${WRKSRC}
.endif

do-install:
.if !empty(GS_CIDFMAP)
	${INSTALL_DATA} ${WRKSRC}/${GS_CIDFMAP} ${DESTDIR}${PREFIX}/${GS_RESOURCEDIR}/Init/cidfmap
.endif
	# mainly Ryumin and GothicBBB
	${INSTALL_DATA} files/${GCR_INSTALL_TYPE}/[GR]*   ${DESTDIR}${PREFIX}/${GS_RESOURCEDIR}/Font

# no need to edit cidfmap
.if empty(GS_CIDFMAP)
NO_BUILD=	yes
.endif

NO_CHECKSUM=	yes
NO_CONFIGURE=	yes

.include "../../print/ghostscript-gpl/buildlink3.mk"

.if empty(PKG_BUILD_OPTIONS.ghostscript-gpl:Mdisable-compile-inits)
PKG_FAIL_REASON+=	'You need to set PKG_OPTIONS.ghostscript+= disable-compile-inits, at its compile time.'
.endif

#.include "../../fonts/adobe-cidfonts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
