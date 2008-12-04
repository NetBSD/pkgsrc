# $NetBSD: Makefile,v 1.1.1.1.4.1 2008/12/04 10:14:05 tron Exp $
#

DISTNAME=	slang-2.1.3
PKGREVISION=	1
PKGNAME=	lib${DISTNAME:slang%=slang2%}
SVR4_PKGNAME=	lslan
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v2.1/ \
		http://gd.tuwien.ac.at/editors/davis/slang/v2.1/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slang/v2.1/ \
		ftp://ftp.plig.org/pub/slang/v2.1/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.s-lang.org/
COMMENT=	Routines for rapid alpha-numeric terminal applications development

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

BUILDLINK_TRANSFORM+=	l:slang:slang2

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--without-x

DLOPEN_REQUIRE_PTHREADS=no

EGDIR=			${PREFIX}/share/examples/libslang2
CONF_FILES+=		${EGDIR}/slsh.rc ${PKG_SYSCONFDIR}/slsh.rc

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

USE_FEATURES=		# empty (used in options.mk)
.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
