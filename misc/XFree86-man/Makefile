# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 09:07:03 xtraeme Exp $

DISTNAME=	X430src-1
PKGNAME=	XFree86-man-${XF_VER}
WRKSRC=		${WRKDIR}/xc/doc/man
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Manuals

BUILD_DEPENDS=	imake>=4.3.0:../../x11/imake

USE_BUILDLINK2=		yes

NO_XFREE86_TARGETS=	# defined
INSTALL_TARGET=		install.man

post-extract:
	@${SED} \
		-e "s|@PREFIX@|${X11PREFIX}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|g" \
		-e "s|@IMAKE@|${IMAKE}|g" \
		${FILESDIR}/host.def > ${WRKSRC}/host.def

# XXX please share suggestion on how to do this correctly
pre-configure:
.for F in general X11 GL/gl GL/glx GLU GLw Xv Xau Xt Xext Xext/dbe Xi
	@${LN} -sf ${WRKSRC}/host.def ${WRKSRC}/${F}/
.endfor
.undef F

do-configure:
	(cd ${WRKSRC} ; \
	${IMAKE} -DUseInstalled -I. -I${PREFIX}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend)

.include "../../meta-pkgs/XFree86/Makefile.common"

.include "../../mk/bsd.pkg.mk"
