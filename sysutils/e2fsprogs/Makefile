# $NetBSD: Makefile,v 1.15 2007/07/29 16:17:12 joerg Exp $
#

DISTNAME=	e2fsprogs-1.39
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=e2fsprogs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://e2fsprogs.sourceforge.net/
COMMENT=	Second extended file system (ext2fs) management programs

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	makeinfo
INFO_FILES=	# PLIST

.include "../../mk/bsd.prefs.mk"

# Only build fsck(8) on platforms that need it.
.if (${OPSYS} != "Linux")
FSCK=		"@comment "
.else
FSCK=		# empty
.endif
PLIST_SUBST+=	FSCK=${FSCK}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
.if !empty(FSCK)
CONFIGURE_ARGS+=	--disable-fsck
.endif

EGDIR=			${PREFIX}/share/examples/ext2fs
CONF_FILES+=		${EGDIR}/mke2fs.conf ${PKG_SYSCONFDIR}/mke2fs.conf
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} root_sysconfdir=${EGDIR:Q}

.include "../../mk/bsd.pkg.mk"
