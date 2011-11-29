# $NetBSD: Makefile,v 1.66 2011/11/29 17:55:07 drochner Exp $

DISTNAME=	xfig.3.2.5b.full
PKGNAME=	xfig-3.2.5b
PKGREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xfig.org/
COMMENT=	CAD-like 2D drawing tool, good for colorful scale drawings & ISOs

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	transfig>=3.2.4:../../print/transfig
# if we're using Xaw3d, then we need 1.5E or newer since using that
# version means we need a patch, which is currently used unconditionally
BUILDLINK_API_DEPENDS.Xaw3d+=	Xaw3d>=1.5E

WRKSRC=			${WRKDIR}/xfig.3.2.5b
USE_IMAKE=		YES
XAW_TYPE?=		3d

NO_INSTALL_MANPAGES=	YES	# install.all does install.man
INSTALL_TARGET=		install install.all
CFLAGS+=		-I${X11PREFIX}/include/X11

.include "../../mk/bsd.prefs.mk"

post-extract:
	cd ${WRKSRC} && ${RM} -f Doc/*.orig Doc/*/*.orig Doc/*/*.save Doc/*/*/*.orig
	find ${WRKSRC}/Libraries -type d -exec ${CHMOD} 0755 {} \;
	find ${WRKSRC}/Libraries -type f -exec ${CHMOD} 0644 {} \;
	find ${WRKSRC}/Doc -type d -exec ${CHMOD} 0755 {} \;
	find ${WRKSRC}/Doc -type f -exec ${CHMOD} 0644 {} \;

SUBST_CLASSES+=		xaw
SUBST_STAGE.xaw=	post-patch
SUBST_MESSAGE.xaw=	Fixing Imakefile
SUBST_FILES.xaw=	Imakefile
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

SUBST_CLASSES+=		i18n
SUBST_STAGE.i18n=	post-patch
SUBST_MESSAGE.i18n=	Enabling I18N
SUBST_FILES.i18n=	Imakefile
SUBST_SED.i18n+=	-e 's/XCOMM \(\#define I18N\)/\1/'

XFIGDOCDIR=		${PREFIX}/share/doc/xfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/Doc/FORMAT?.? ${DESTDIR}${XFIGDOCDIR}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
