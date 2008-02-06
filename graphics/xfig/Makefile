# $NetBSD: Makefile,v 1.53 2008/02/06 23:33:00 smb Exp $

DISTNAME=	xfig.3.2.5-alpha5.full
PKGNAME=	xfig-3.2.5alpha5
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	ftp://epb.lbl.gov/xfig/alpha/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xfig.org/
COMMENT=	CAD-like 2D drawing tool, good for colorful scale drawings & ISOs

DEPENDS+=	transfig>=3.2.4:../../print/transfig
# if we're using Xaw3d, then we need 1.5E or newer since using that
# version means we need a patch, which is currently used unconditionally
BUILDLINK_API_DEPENDS.Xaw3d+=	Xaw3d>=1.5E

WRKSRC=			${WRKDIR}/xfig.3.2.5-alpha5
USE_IMAKE=		YES
XAW_TYPE?=		3d

NO_INSTALL_MANPAGES=	YES	# install.all does install.man
INSTALL_TARGET=		install install.all
CFLAGS+=		-I${X11PREFIX}/include/X11

.include "../../mk/bsd.prefs.mk"

post-extract:
	cd ${WRKSRC} && ${RM} -f Doc/*.orig Doc/*/*.orig Doc/*/*/*.orig

SUBST_CLASSES+=		xaw
SUBST_STAGE.xaw=	post-configure
SUBST_MESSAGE.xaw=	Fixing Imakefile
SUBST_FILES.xaw=	IMakefile
.if defined(XAW_TYPE) && ${XAW_TYPE} == "3d"
# define XAW3D and XAW3D1_5E
SUBST_SED.xaw+=		-e 's/.*\(\#define.XAW3D\)/\1/'
.elif defined(XAW_TYPE) && ${XAW_TYPE} == "xpm"
#  define XAW3D, undef XAW3D1_5E
SUBST_SED.xaw+=		-e 's/.*\(\#define.XAW3D1_5E\)/XCOMM \1/'
SUBST_SED.xaw+=		-e t
SUBST_SED.xaw+=		-e 's/.*\(\#define.XAW3D\)/\1/'
.else
# undef XAW3D and XAW3D1_5E
SUBST_SED.xaw+=		-e 's/.*\(\#define.XAW3D\)/XCOMM \1/'
.endif

XFIGDOCDIR=		${PREFIX}/share/doc/xfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/FORMAT?.? ${XFIGDOCDIR}

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
