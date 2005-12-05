# $NetBSD: Makefile,v 1.5 2005/12/05 20:51:01 rillig Exp $
#

DISTNAME=		sformat-3.5
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.berlios.de/pub/sformat/

MAINTAINER=		Andreas.Hallmann@tiscali.de,tech-pkg@NetBSD.org
HOMEPAGE=		http://freshmeat.net/projects/sformat
COMMENT=		SCSI disk maintainance, formating, and ultimative repair tool with support for NetBSD labels

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake
TBL?=			tbl

# avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""
MAKE_ENV+=      MAKEPROG="gmake"
MAKE_ENV+=	COPTX=${CFLAGS:M*:Q}
MAKE_ENV+=	LDOPTX=${LDFLAGS:M*:Q}
MAKE_FLAGS+=	INS_BASE=${LOCALBASE:Q}	# won't work in MAKE_ENV!

# if we're using a gcc which is named gcc, we need to set CCOM=gcc
# in MAKE_ENV so the make infrastructure picks the right options.
.if !empty(CC:M*gcc*)
MAKE_ENV+=	CCOM="gcc"
.endif

INSTALLATION_DIRS=	bin include lib man/man5 man/man8

.include "../../mk/bsd.pkg.mk"
