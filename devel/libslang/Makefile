# $NetBSD: Makefile,v 1.75 2025/01/06 21:36:24 ktnb Exp $

DISTNAME=	slang-2.3.3
PKGNAME=	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://www.jedsoft.org/releases/slang/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.jedsoft.org/slang/
COMMENT=	Routines for rapid alpha-numeric terminal applications development
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-z=${BUILDLINK_PREFIX.zlib}

PKGCONFIG_OVERRIDE+=	autoconf/slangpc.in

DLOPEN_REQUIRE_PTHREADS=	no

EGDIR=		${PREFIX}/share/examples/libslang
CONF_FILES+=	${EGDIR}/slsh.rc ${PKG_SYSCONFDIR}/slsh.rc

INSTALL_MAKE_FLAGS+=	DEST_SLSH_CONF_DIR=${DESTDIR}/${EGDIR}

.include "../../mk/termcap.buildlink3.mk"

#CONFIGURE_ENV+=		TERMCAP=
CONFIGURE_ENV+=		MISC_TERMINFO_DIRS=${BUILDLINK_PREFIX.termcap}/share/terminfo

REPLACE_INTERPRETER+=	slsh
REPLACE.slsh.old=	slsh
REPLACE.slsh.new=	${PREFIX}/bin/slsh
REPLACE_FILES.slsh=	slsh/scripts/jpegsize slsh/scripts/lsrpm \
			slsh/scripts/sldb slsh/scripts/slprof \
			slsh/scripts/svnsh slsh/scripts/slstkchk \
			slsh/scripts/slcov

USE_FEATURES=		# empty (used in options.mk)
.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
