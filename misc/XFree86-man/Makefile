# $NetBSD: Makefile,v 1.9 2005/09/28 20:52:24 rillig Exp $

DISTNAME=	XFree86-${XF_VER}-src-1
PKGNAME=	XFree86-man-${XF_VER}
CATEGORIES=	misc x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Manuals

DEPENDS=	imake>=${XF_VER}:../../x11/imake

USE_LANGUAGES=		# empty
NO_XFREE86_TARGETS=	yes
WRKSRC=			${WRKDIR}/xc/doc/man
INSTALL_TARGET=		install.man

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
