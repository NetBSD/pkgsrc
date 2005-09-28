# $NetBSD: Makefile,v 1.10 2005/09/28 20:52:24 rillig Exp $

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
NO_XFREE86_TARGETS=	yes
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
