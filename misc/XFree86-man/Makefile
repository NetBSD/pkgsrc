# $NetBSD: Makefile,v 1.4 2004/02/02 14:20:28 xtraeme Exp $

DISTNAME=	X430src-1
PKGNAME=	XFree86-man-${XF_VER}
PKGREVISION=	1
CATEGORIES=	misc x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Manuals

BUILD_DEPENDS=	imake>=4.3.0:../../x11/imake

USE_IMAKE=		yes
USE_BUILDLINK2=		yes
WRKSRC=			${WRKDIR}/xc/doc/man

NO_XFREE86_TARGETS=	# defined
INSTALL_TARGET=		install.man

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PLIST_SUBST+=		MANPAGE_SUFFIX=${IMAKE_MANNEWSUFFIX}
.else
PLIST_SUBST+=		MANPAGE_SUFFIX=${IMAKE_LIBMAN_SUFFIX}
.endif

post-extract:
	@${SED} \
		-e "s|@PREFIX@|${X11ROOT}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|g" \
		-e "s|@IMAKE@|${IMAKE}|g" \
		${FILESDIR}/host.def > ${WRKSRC}/host.def

pre-configure:
.for F in general X11 GL GL/gl GL/glx GLU GLw Xv Xau Xt Xext Xext/dbe Xi
	@${LN} -sf ${WRKSRC}/host.def ${WRKSRC}/${F}/
.endfor
.undef F

do-configure:
	(cd ${WRKSRC} ; \
	${IMAKE} -DUseInstalled -I. -I${X11ROOT}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
