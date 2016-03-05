# $NetBSD: Makefile,v 1.37 2016/03/05 15:44:36 bsiegert Exp $

DISTNAME=		file-5.25
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.astron.com/pub/file/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.darwinsys.com/file/
COMMENT=		Tool for determining file type
LICENSE=		2-clause-bsd

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
BUILDLINK_TRANSFORM+=	opt:-Wextra:-W
.endif
# gcc<3 does not know -Wunused-parameter
.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=  rm:-Wunused-parameter
.endif

CFLAGS.AIX+=	-D_LINUX_SOURCE_COMPAT

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
