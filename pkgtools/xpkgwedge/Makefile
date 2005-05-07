# $NetBSD: Makefile,v 1.55 2005/05/07 22:24:04 wiz Exp $

DISTNAME=	xpkgwedge-1.12
CATEGORIES=	pkgtools devel x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	ftp://ftp.NetBSD.org/pub/NetBSD/packages/pkgsrc/doc/pkgsrc.html
COMMENT=	Allows X11 pkgs to be built and used outside of $${X11BASE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
USE_LANGUAGES=	# empty
NO_CONFIGURE=	# defined
NO_CHECKSUM=	# defined

.include "../../mk/bsd.prefs.mk"
.if ${LOCALBASE} == ${X11BASE}
PKG_SKIP_REASON+=	"xpkgwedge is not needed when X11BASE is LOCALBASE"
.endif

.if exists(${X11BASE}/bin/mkfontscale)
CONFLICTS+=	mkfontscale-[0-9]*
.endif

USE_X11=		YES
USE_PKGINSTALL=		YES
DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL
INSTALLATION_DIRS=	bin lib/X11/config

# FONT_PROGS are symlinked from ${X11BASE}/bin to ${PREFIX}/bin to allow
# ${PREFIX}/bin/${prog} to always work.
#
FONT_PROGS=		bdftopcf fstobdf mkfontdir mkfontscale

FILES_SUBST+=		VIEWBASE=${VIEWBASE}
FILES_SUBST+=		FONT_PROGS=${FONT_PROGS:Q}
FILES_SUBST+=		MAKE=${MAKE_PROGRAM:Q}

post-extract:
	@${CP} ${FILESDIR}/xpkgwedge.def ${WRKSRC}

do-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/pkgxmkmf.in > ${WRKDIR}/pkgxmkmf

.if defined(X11_TYPE) && !empty(X11_TYPE:Mxorg) || \
    defined(X11_TYPE) && !empty(X11_TYPE:MXFree86)
X11TYPEFLAGS?=		-L${X11BASE}/lib ${COMPILER_RPATH_FLAG}${X11BASE}/lib
SUBST_CLASSES=		fix
SUBST_STAGE.fix=	post-patch
SUBST_FILES.fix=	xpkgwedge.def
SUBST_SED.fix=		-e "s|@X11TYPEFLAGS@|${X11TYPEFLAGS}|"
.else # X11_TYPE == XFree86 || X11_TYPE == xorg.
SUBST_CLASSES=		foo
SUBST_STAGE.foo=	post-patch
SUBST_FILES.foo=	xpkgwedge.def
SUBST_SED.foo=		-e "s|\#define ExtraLoadFlags @X11TYPEFLAGS@||"
.endif # X11_TYPE == native.

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/config
	${INSTALL_DATA} ${WRKSRC}/xpkgwedge.def ${PREFIX}/lib/X11/config
	${INSTALL_SCRIPT} ${WRKSRC}/pkgxmkmf ${PREFIX}/bin/pkgxmkmf

.include "../../mk/bsd.pkg.mk"
