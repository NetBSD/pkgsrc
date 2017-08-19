# $NetBSD: Makefile,v 1.18 2017/08/19 00:25:19 jlam Exp $
#

DISTNAME=	sformat-3.5
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/sformat/

MAINTAINER=	Andreas.Hallmann@tiscali.de
HOMEPAGE=	http://freshmeat.net/projects/sformat
COMMENT=	SCSI disk maintainance, formating, and ultimative repair tool

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		gmake
TBL?=			tbl

# avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=	ARCH=""
MAKE_ENV+=	MAKEPROG="gmake"
MAKE_ENV+=	COPTX=${CFLAGS:M*:Q}
MAKE_ENV+=	LDOPTX=${LDFLAGS:M*:Q}

# Override settings in Makefiles by passing additional settings
# on the command-line.
#
MAKE_FLAGS+=	INS_BASE=${DESTDIR}${LOCALBASE:Q}
MAKE_FLAGS+=	MANDIR=${PKGMANDIR:Q}

# if we're using a gcc which is named gcc, we need to set CCOM=gcc
# in MAKE_ENV so the make infrastructure picks the right options.
.if !empty(CC:M*gcc*)
MAKE_ENV+=	CCOM="gcc"
.endif

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

post-extract:
	${CP} ${WRKSRC}/RULES/os-freebsd.id ${WRKSRC}/RULES/os-dragonfly.id
	${CP} ${WRKSRC}/RULES/os-freebsd.def ${WRKSRC}/RULES/os-dragonfly.def
.for x in amd64 macppc
	ln -s i386-netbsd-cc.rul ${WRKSRC}/RULES/${x}-netbsd-cc.rul
	ln -s i386-netbsd-cc.rul ${WRKSRC}/RULES/${x}-netbsd-gcc.rul
.endfor

.include "../../mk/bsd.pkg.mk"
