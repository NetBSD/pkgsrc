# $NetBSD: Makefile,v 1.16 2013/12/30 13:07:46 ryoon Exp $
#

DISTNAME=	slang-2.2.4
PKGNAME=	lib${DISTNAME:slang%=slang2%}
PKGREVISION=	2
SVR4_PKGNAME=	lslan
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v2.2/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slang/v2.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jedsoft.org/slang/
COMMENT=	Routines for rapid alpha-numeric terminal applications development
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_JOBS_SAFE=		no

BUILDLINK_TRANSFORM+=	l:slang:slang2

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-z=${BUILDLINK_PREFIX.zlib}

DLOPEN_REQUIRE_PTHREADS=no

EGDIR=			${PREFIX}/share/examples/libslang2
CONF_FILES+=	${EGDIR}/slsh.rc ${PKG_SYSCONFDIR}/slsh.rc

INSTALL_MAKE_FLAGS+=	DEST_SLSH_CONF_DIR=${DESTDIR}/${EGDIR}

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/slang2

.include "../../mk/termcap.buildlink3.mk"

.if ${TERMCAP_TYPE} == "termcap"
CONFIGURE_ENV+=		TERMCAP=${BUILDLINK_LDADD.termcap:Q}
CONFIGURE_ENV+=		MISC_TERMINFO_DIRS=${PREFIX}/share/terminfo
.else
CONFIGURE_ENV+=		TERMCAP=
CONFIGURE_ENV+=		MISC_TERMINFO_DIRS=${BUILDLINK_PREFIX.termcap}/share/terminfo
.endif

REPLACE_INTERPRETER+=	slsh
REPLACE.slsh.old=	slsh
REPLACE.slsh.new=	${PREFIX}/bin/slsh
REPLACE_FILES.slsh=	slsh/scripts/jpegsize slsh/scripts/lsrpm \
			slsh/scripts/sldb slsh/scripts/slprof \
			slsh/scripts/svnsh slsh/scripts/slstkchk

USE_FEATURES=		# empty (used in options.mk)
.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
