# $NetBSD: Makefile,v 1.5 2004/03/28 22:06:15 xtraeme Exp $

DISTNAME=	XFree86-4.4.0-src-1
PKGNAME=	XFree86-man-${XF_VER}
CATEGORIES=	misc x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Manuals

DEPENDS=	imake>=4.4.0:../../x11/imake

USE_LANGUAGES=		# empty
NO_BUILDLINK=		# defined
NO_XFREE86_TARGETS=	# defined
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
