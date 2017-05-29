# $NetBSD: Makefile,v 1.93 2017/05/29 11:09:46 jperkin Exp $

DISTNAME=	rpm-4.13.0.1
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://ftp.rpm.org/releases/rpm-4.13.x/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rpm.org/
COMMENT=	The Red Hat Package Manager
LICENSE=	gnu-lgpl-v2 OR gnu-gpl-v2

CONFLICTS+=		rpm2cpio<1.0nb1

NOT_FOR_PLATFORM+=	Interix-*-* # getmntent() is nonpublic; needs porting

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf bash:run gmake msgfmt perl:run pkg-config
GNU_CONFIGURE=		yes
# this is needed in addition of USE_PKGLOCALEDIR
CONFIGURE_ARGS+=	--datadir=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--with-external-db
CONFIGURE_ARGS+=	--with-vendor=pkgsrc
CONFIGURE_ARGS+=	--without-lua
# avoid build directory references
CONFIGURE_ENV+=		MYPATH=/sbin:/bin:/usr/sbin:/usr/bin
# rpm databases are kept under ${RPM_DB_PREFIX}/lib/rpm.
CONFIGURE_ENV+=		varprefix=${RPM_DB_PREFIX:Q}
CONFIGURE_ENV.Darwin+=	ac_cv_func_fdatasync=no

PKGCONFIG_OVERRIDE=	rpm.pc.in

GMAKE_REQD=		3.82nb1

REPLACE_BASH+=		installplatform
REPLACE_BASH+=		scripts/brp-python-bytecompile
REPLACE_BASH+=		scripts/check-prereqs
REPLACE_BASH+=		scripts/check-rpaths-worker
REPLACE_BASH+=		scripts/find-debuginfo.sh
REPLACE_BASH+=		scripts/fontconfig.prov
REPLACE_BASH+=		scripts/mono-find-provides
REPLACE_BASH+=		scripts/mono-find-requires
REPLACE_BASH+=		scripts/pkgconfigdeps.sh
REPLACE_BASH+=		scripts/pythondeps.sh
REPLACE_BASH+=		scripts/rpmdb_loadcvt
REPLACE_PERL+=		scripts/perl.prov
REPLACE_PERL+=		scripts/perl.req

BDB_ACCEPTED=		db4 db5
.include "../../mk/bdb.buildlink3.mk"
.if ${BDB_TYPE} == "db4"
BUILDLINK_TRANSFORM+=	l:db:db4
.else
BUILDLINK_TRANSFORM+=	l:db:db5
.endif

LDFLAGS+=		${PTHREAD_LDFLAGS}

MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man8
MAKE_FLAGS+=		ROOT=${DESTDIR}

RPMDIR=			${RPM_DB_PREFIX}/lib/rpm
FILES_SUBST+=		RPMDIR=${RPMDIR}

# The configure script doesn't detect whether libintl.so has any
# library dependencies.
BROKEN_GETTEXT_DETECTION=	yes

CHECK_PORTABILITY_SKIP=	tests/rpmtests

SUBST_CLASSES+=		mkd
SUBST_STAGE.mkd=	post-build
SUBST_MESSAGE.mkd=	Fixing workdir tools references in macros file.
SUBST_FILES.mkd=	macros
SUBST_SED.mkd=		-e 's,${TOOLS_CMD.mkdir},${TOOLS_PATH.mkdir},'

# __progname without 'extern' segfaults on some platforms (e.g. Darwin)
SUBST_CLASSES+=		progname
SUBST_STAGE.progname=	pre-configure
SUBST_MESSAGE.progname=	Fixing __progname declarations to include 'extern'.
SUBST_FILES.progname=	lib/poptALL.c
SUBST_FILES.progname+=	rpm2archive.c
SUBST_FILES.progname+=	rpm2cpio.c
SUBST_FILES.progname+=	rpmbuild.c
SUBST_FILES.progname+=	rpmqv.c
SUBST_FILES.progname+=	rpmspec.c
SUBST_FILES.progname+=	tools/rpmdeps.c
SUBST_FILES.progname+=	tools/rpmgraph.c
SUBST_SED.progname=	-e 's,^const char \*__progname;,extern &,'

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk" # for libmagic.
.include "../../mk/bsd.pkg.mk"
