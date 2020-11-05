# $NetBSD: Makefile,v 1.144 2020/11/05 09:07:06 ryoon Exp $

DISTNAME=	heimdal-1.5.3
PKGREVISION=	27
CATEGORIES=	security
# Original distfile is unavailable on Github
#GITHUB_TAG=	${DISTNAME}
#MASTER_SITES=	${MASTER_SITE_GITHUB:=heimdal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.h5l.org/
COMMENT=	Kerberos 5 implementation
LICENSE=	modified-bsd

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	mit-krb5-[0-9]*
CONFLICTS+=	openafs-[0-9]*
CONFLICTS+=	gss-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex:run
PKGCONFIG_OVERRIDE+=	tools/heimdal-gssapi.pc.in
MAKE_ENV+=		INSTALL_CATPAGES=no

# heimdal-1.5.3 on NetBSD 8.1 fails with:
# cc [...] -c hxtool.c
# In file included from hxtool.c:34:0:
# hx_locl.h:66:23: fatal error: ocsp_asn1.h: No such file or directory 
#
# https://mail-index.netbsd.org/pkgsrc-users/2020/02/20/msg030473.html
MAKE_JOBS_SAFE=		no

.include "options.mk"

HEIMDAL_HDB_DIR=	${VARBASE}/heimdal

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has multiple configure scripts
CONFIGURE_ARGS+=	--enable-kcm
CONFIGURE_ARGS+=	--enable-pthread-support
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/krb5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-hdbdir=${HEIMDAL_HDB_DIR}
# not compatible to openssl 1.1
# TODO: re-enable when updating from 1.5.3, also in buildlink3.mk
CONFIGURE_ARGS+=	--without-openssl
CONFIGURE_ARGS+=	--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	${ABI:D--with-mips-abi=${ABI}}
CONFIGURE_ENV+=		COMPILE_ET=no	# build Heimdal's compile_et(1)
# XXX Grand Central Dispatch is broken in 1.4
CONFIGURE_ENV+=		ac_cv_funclib_dispatch_async_f=no

.include "../../mk/bdb.buildlink3.mk"

# XXX Don't detect db1 when a newer version is available; otherwise build fails
.if ${BDB_TYPE} != "db1"
CONFIGURE_ENV+=		ac_cv_funclib_dbopen=no
.endif

CFLAGS.Darwin+=		-DBIND_8_COMPAT

# Newer illumos has extended functions in glob(3C) but it's easier to
# say it doesn't for simpler PLIST.glob handling.
CONFIGURE_ENV.SunOS+=	ac_cv_func_glob_working=no

# Though Solaris has a <vis.h> header, it does something very unrelated
# to the BSD <vis.h> header.
CONFIGURE_ENV.SunOS+=	ac_cv_header_vis_h=no

.include "../../mk/readline.buildlink3.mk"

.if ${READLINE_TYPE} == "readline"
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.editlinereadline}
.elif ${READLINE_TYPE} == "editline"
CONFIGURE_ARGS+=	--with-libedit=${BUILDLINK_PREFIX.editlinereadline}
.endif

PLIST_VARS+=		glob vis hcrypto afskauth

.if ${OPSYS} == "SunOS"
PLIST.vis=	yes
PLIST.glob=	yes
.endif

.if ${OPSYS} == "IRIX"
PLIST.afskauth=		yes
.endif

OWN_DIRS_PERMS=		${HEIMDAL_HDB_DIR} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
SPECIAL_PERMS+=		${PREFIX}/bin/otp ${SETUID_ROOT_PERMS}
SPECIAL_PERMS=		${PREFIX}/bin/${KRB5_PREFIX}su ${SETUID_ROOT_PERMS}
RCD_SCRIPTS=		kadmind kcm kdc kpasswdd
INFO_FILES=		yes

TEST_TARGET=		check

# remove manpages conficting with OpenSSL keeping only the important ones
pre-configure:
	cd ${WRKSRC}/doc/doxyout/hcrypto && \
	${GREP} -e /hcrypto_ -e /page_ manpages > manpages.new && \
	mv manpages.new manpages

# Avoid 'cat: cannot open ./localefiles: No such file or directory'
pre-build:
	${TOUCH} ${WRKSRC}/po/localefiles

.include "../../databases/sqlite3/buildlink3.mk"
PLIST.hcrypto=		yes

# Linux does not have include/vis.h and expected include/glob.h.
.if ${OPSYS} == "Linux"
PLIST.vis=		yes
PLIST.glob=		yes
# Without this I get undefined references to pthread_getspecific
PTHREAD_AUTO_VARS=	yes
.endif

.if ${OPSYS} == "MirBSD"
PLIST.vis=		yes
# all of the tools need to link against pthread, force it.
PTHREAD_AUTO_VARS=	yes
.endif

.if ${OPSYS} == "Minix"
# all of the tools need to link against pthread, force it.
PTHREAD_AUTO_VARS=	yes
.endif

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
