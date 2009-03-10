# $NetBSD: Makefile,v 1.20 2009/03/10 23:30:00 he Exp $

DISTNAME=		file-5.00
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/mirrors/pub/unix/file/
MASTER_SITES+=		ftp://ftp.astron.com/pub/file/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=		Tool for determining file type

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fsect-man5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

TEST_TARGET=		check

.include "../../mk/compiler.mk"

# gcc<4 does not know -Wextra.
# XXX: should be treated with wrappers automatically.
.if !empty(CC_VERSION:Mgcc-[23]*)
BUILDLINK_TRANSFORM+=	rename:-Wextra:-W
.endif

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
