# $NetBSD: Makefile,v 1.8 2004/07/31 02:28:15 xtraeme Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		XFree86-docs-${XF_VER}
CATEGORIES=		misc x11
MASTER_SITES=		${MASTER_SITE_XFREE}
DISTFILES+=		XFree86-${XF_VER}-src-1.tgz XFree86-${XF_VER}-src-6.tgz

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.xfree86.org/
COMMENT=		XFree86 Documentation

DEPENDS=		imake>=${XF_VER}:../../x11/imake

USE_LANGUAGES=		# empty
NO_BUILDLINK=		# defined
NO_XFREE86_TARGETS=	# defined
WRKSRC=			${WRKDIR}/xc/doc/specs

pre-configure:
	@${SED} \
		-e "s|@PREFIX@|${X11ROOT}|g" \
		-e "s|@MAKE@|${MAKE_PROGRAM}|g" \
		-e "s|@IMAKE@|${IMAKE}|g" \
		${FILESDIR}/host.def > ${WRKSRC}/host.def

do-configure:
	( cd ${WRKSRC}; \
	${IMAKE} -DUseInstalled -I. -I${X11ROOT}/lib/X11/config \
		-DTOPDIR=../.. -DCURDIR=.; \
	${MAKE} Makefiles ; \
	${MAKE} includes ; \
	${MAKE} depend )

.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
