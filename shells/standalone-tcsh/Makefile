# $NetBSD: Makefile,v 1.34 2021/11/14 22:36:12 kim Exp $
#

# FIXME: This is because of PREFIX=/ below.
CHECK_FILES_SUPPORTED=	no
NOT_FOR_UNPRIVILEGED=	yes

PKGNAME=		standalone-${DISTNAME}
PKGREVISION=		1

WRKSRC=			${WRKDIR}/${DISTNAME}
PATCHDIR=		${.CURDIR}/../../shells/tcsh/patches

# This package only makes sense on platforms that don't themselves ship tcsh
# in /bin. Otherwise it clobbers the native copy, which really isn't what
# anyone wants.
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* SunOS-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OS_VARIANT} == "OmniOS"
NOT_FOR_PLATFORM+=	SunOS-*-*
.endif

.include "../../shells/tcsh/Makefile.common"
.include "../../mk/bsd.pkg.mk"

INSTALLATION_DIRS+=	usr/share/man/man1

COMMENT:=		Standalone version of the Extended C-shell
MAINTAINER=		agc@NetBSD.org

# FIXME: Packages shall only install into ${LOCALBASE} or a subdirectory.
PREFIX=			/
EGDIR=			/usr/share/examples/tcsh
NOT_FOR_BULK_PLATFORM=	*-*-*

NLSDIR=			usr/share/nls
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--bindir=/bin
CONFIGURE_ARGS+=	--mandir=/usr/share/man
CONFIGURE_ARGS+=	--disable-nls-catalogs

DISTINFO_FILE=		${.CURDIR}/../../shells/tcsh/distinfo

.if ${OPSYS} != "SunOS"
LDFLAGS+=		-static
.endif
