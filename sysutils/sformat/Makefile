# $NetBSD: Makefile,v 1.2 2005/02/21 20:26:14 hubertf Exp $
#

DISTNAME=		sformat-3.5
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.berlios.de/pub/sformat/

MAINTAINER=		Andreas.Hallmann@tiscali.de,tech-pkg@NetBSD.org
HOMEPAGE=		http://freshmeat.net/projects/sformat
COMMENT=		SCSI-disk maintainance, formating, and ultimative repair tool with support for netbsd labels

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
TBL?=			tbl

# avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""
MAKE_ENV+=      MAKEPROG="gmake"
MAKE_ENV+=	COPTX="${CFLAGS}"
MAKE_ENV+=	LDOPTX="${LDFLAGS}"
MAKE_FLAGS+=	INS_BASE="${LOCALBASE}"	# won't work in MAKE_ENV!

# if we're using a gcc which is named gcc, we need to set CCOM=gcc
# in MAKE_ENV so the make infrastructure picks the right options.
.if !empty(CC:M*gcc*)
MAKE_ENV+=	CCOM="gcc"
.endif

INSTALLATION_DIRS=	bin include lib man/man5 man/man8

.include "../../mk/bsd.pkg.mk"
