# $NetBSD: Makefile,v 1.83 2014/07/18 11:12:41 ryoon Exp $
#
# Please run 'make files/gtar.1' when updating version of this package
# to regenerate the man page. converters/help2man is needed.

DISTNAME=	tar-1.27.1
PKGNAME=	${DISTNAME:S/tar/gtar-base/}
PKGREVISION=	1
SVR4_PKGNAME=	gtarb
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU:=tar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/tar/tar.html
COMMENT=	The GNU tape archiver with remote magnetic tape support
LICENSE=	gnu-gpl-v3

CONFLICTS=	gcpio-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_FEATURES=		snprintf
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt
GNU_CONFIGURE=		yes

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

PLIST_VARS+=		gtar rmt

TEST_TARGET=		check

# don't include rmt if gtar won't build it
.if ${OPSYS} != "Interix" && ${OPSYS} != "Darwin" && ${OS_VARIANT} != "SCOOSR5"
PLIST.rmt=		yes
.endif

# XXX see similar hack in coreutils.
.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		gt_cv_func_gnugettext3_libintl=yes
.endif

.if ${OPSYS} == "MirBSD"
CPPFLAGS+=		-Dstrtoimax=strtoll -Dstrtoumax=strtoull
.endif

SYMLINKS=		bin/gtar ${PKGGNUDIR}bin/tar \
			${PKGMANDIR}/man1/gtar.1 ${PKGGNUDIR}${PKGMANDIR}/man1/tar.1

.if defined(PLIST.rmt) && ${PLIST.rmt} == "yes"
SYMLINKS+=		libexec/grmt ${PKGGNUDIR}libexec/rmt
.endif

.if ${OS_VARIANT} == "SCOOSR5"
# SCO OpenServer 5.0.7/3.2 has strtoimax() declaration in inttypes.h,
# but libc.so has no implementation. And gnulib in GNU tar 1.27 has broken
# strtoimax() support. We have to use BSDL implementation instead.
pre-configure:
	cd ${WRKSRC} && ${CC} -c -o strtoimax.o strtoimax.c
.endif

files/gtar.1: build
	${ECHO} .\\\" > ${FILESDIR}/gtar.1
	${ECHO} .\\\" \$$NetBSD\$$ >> ${FILESDIR}/gtar.1
	help2man --name "The GNU version of the tar archiving utility" \
		--info-page tar ${WRKSRC}/src/tar | \
		${SED} '/help2man/d' >> ${FILESDIR}/gtar.1

post-install:
	${INSTALL_MAN} ${FILESDIR}/gtar.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gtar.1
.for o n in ${SYMLINKS}
	${LN} -sf ${PREFIX}/${o} ${DESTDIR}${PREFIX}/${n}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
