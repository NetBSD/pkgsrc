# $NetBSD: Makefile,v 1.2 1998/09/15 17:05:05 agc Exp $
# FreeBSD Id: Makefile,v 1.6 1998/02/11 08:48:26 tg Exp
#

DISTNAME=	urt
PKGNAME=	urt-3.1b1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cs.utah.edu/pub/
DISTFILES=	urt-3.1b.tar.Z urt-doc.tar urt-img.tar

MAINTAINER=	packages@netbsd.org

.include "../../mk/bsd.prefs.mk"

.ifdef WRKOBJDIR
BUILD_ROOT=	${WRKOBJDIR}
.else
BUILD_ROOT=	${PKGSRCDIR}
.endif

DEPENDS+=	tiff-3.4:../../graphics/tiff
BUILD_DEPENDS+=	${BUILD_ROOT}/graphics/netpbm/${WRKDIR:T}/netpbm:../../graphics/netpbm:build

EXTRACT_ONLY=	urt-3.1b.tar.Z
PATCH_SITES=	ftp://ptolemy.berkeley.edu/pub/misc/urt/
PATCHFILES=	urt-3.1b-3.1b1.patch
PATCH_DIST_STRIP=-p1

NO_WRKSUBDIR=   yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	config/urt
HAS_CONFIGURE=	yes
MAKEFILE=	makefile
MAKE_ENV+=	PKGSRCDIR=${BUILD_ROOT} WORKINGDIRNAME=${WRKDIR:T}
ALL_TARGET=

post-install:
	${MKDIR} ${PREFIX}/share/doc/urt ${PREFIX}/share/examples/urt
	cd ${PREFIX}/share/doc/urt; \
	${EXTRACT_CMD} xf $(DISTDIR)/urt-doc.tar; \
	cd doc; \
	find -d . | cpio -dump ..; \
	cd ..; \
	${RM} -rf doc; \
	cd ${PREFIX}/share/examples/urt; \
	${EXTRACT_CMD} xf $(DISTDIR)/urt-img.tar; \
	chown -R root:wheel . ; \
	find . -type d -exec chmod 775 '{}' \; ; \
	find . -type f -exec chmod 664 '{}' \;

.include "../../mk/bsd.pkg.mk"
