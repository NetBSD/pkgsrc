# $NetBSD: Makefile,v 1.98 2023/10/10 10:27:21 pho Exp $

.include "../../archivers/gtar/Makefile.common"

PKGNAME=	${DISTNAME:S/tar/gtar-base/}

CONFLICTS=	gcpio-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes
TEST_TARGET=		check

INSTALLATION_DIRS=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	${PKGGNUDIR}bin ${PKGGNUDIR}libexec
INSTALLATION_DIRS+=	${PKGGNUDIR}${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--program-prefix=g

# lie to configure about gettext -- it does not need GNU gettext
CONFIGURE_ENV+=		gt_cv_func_gnugettext2_libintl=yes
# allow configure to run as root
CONFIGURE_ENV+=		FORCE_UNSAFE_CONFIGURE=1

.if ${OS_VARIANT} == "SCOOSR5"
# SCO OpenServer 5.0.7/3.2 has strtoimax in inttypes.h, but not in library.
CONFIGURE_ENV+=		gl_cv_have_raw_decl_strtoimax=no
CONFIGURE_ENV+=		ac_cv_have_decl_strtoimax=no
LDFLAGS.SCO_SV+=	-lsocket
.endif

.if ${OPSYS} == "FreeBSD"
.  for p in ${LP32PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${p})
# Required on platforms where time_t is signed 32-bit.
CONFIGURE_ARGS+=	--disable-year2038
.    endif
.  endfor
.endif

PLIST_VARS+=		rmt

# don't include rmt if gtar won't build it
.if ${OPSYS} != "Interix" && ${OPSYS} != "Darwin" && ${OS_VARIANT} != "SCOOSR5" && ${OPSYS} != "AIX"
PLIST.rmt=		yes
.endif

# XXX see similar hack in coreutils.
.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		gt_cv_func_gnugettext3_libintl=yes
.endif

CPPFLAGS.MirBSD+=	-Dstrtoimax=strtoll -Dstrtoumax=strtoull

# From sigwait(3):
CFLAGS.OpenBSD+=	-pthread
LDFLAGS.OpenBSD+=	-pthread

#bug 20453 in bug-gzip list, passed onto gnulib
CONFIGURE_ENV.AIX+=	ac_cv_header_wctype_h=no

SYMLINKS=		bin/gtar ${PKGGNUDIR}bin/tar \
			${PKGMANDIR}/man1/gtar.1 ${PKGGNUDIR}${PKGMANDIR}/man1/tar.1

.if defined(PLIST.rmt) && ${PLIST.rmt} == "yes"
SYMLINKS+=		libexec/grmt ${PKGGNUDIR}libexec/rmt
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/tar.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gtar.1
.for o n in ${SYMLINKS}
	${LN} -sf ${PREFIX}/${o} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
