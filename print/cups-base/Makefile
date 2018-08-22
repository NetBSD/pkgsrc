# $NetBSD: Makefile,v 1.14 2018/08/22 09:46:12 wiz Exp $

.include "../../print/cups/Makefile.common"

DISTNAME=	cups-${CUPS_VERS}-source
PKGNAME=	cups-base-${CUPS_VERS}
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=apple/}

MAINTAINER=	sbd@NetBSD.org
HOMEPAGE=	https://www.cups.org/
COMMENT=	Common UNIX Printing System
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

GITHUB_PROJECT=	cups
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

CONFLICTS+=	LPRng-[0-9]* LPRng-core-[0-9]*

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
UNLIMIT_RESOURCES=	datasize memorysize
USE_LANGUAGES=		c c++	# pdftops is a C++ application
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--with-cachedir=${CUPS_CACHE:Q}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/cups
CONFIGURE_ARGS+=	--with-serverbindir=${PREFIX}/libexec/cups
CONFIGURE_ARGS+=	--with-cups-user=${CUPS_USER}
CONFIGURE_ARGS+=	--with-cups-group=${CUPS_GROUP}
CONFIGURE_ARGS+=	--with-system-groups=${CUPS_SYSTEM_GROUPS:Q}
CONFIGURE_ARGS+=	--with-exe-file-perm=0755
CONFIGURE_ARGS+=	--enable-libpaper
CONFIGURE_ARGS+=	--enable-libtool
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--with-manext=bsd
CONFIGURE_ARGS+=	--without-bundledir
CONFIGURE_ARGS+=	--without-icondir
CONFIGURE_ARGS+=	--without-menudir
CONFIGURE_ARGS+=	--without-perl
CONFIGURE_ARGS+=	--without-php
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--disable-gssapi

CONFIGURE_ENV+=		DSOFLAGS=${LDFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

# Explicitly disable epoll on illumos, it is provided for Linux compat only.
CONFIGURE_ENV.SunOS+=	ac_cv_func_epoll_create=no

LIBS+=			${BUILDLINK_LDADD.iconv}

# Avoid the following error when compiling with clang.
# /usr/local/bin/ld: /usr/lib/crt1.o: relocation R_X86_64_32 against `_DYNAMIC'
# can not be used when making a shared object; recompile with -fPIC
BUILDLINK_TRANSFORM.FreeBSD+=	rm:-Wl,-pie

# CUPS_USER		user to run filter and CGI programs as
# CUPS_GROUP		group to run filter and CGI programs as
# CUPS_SYSTEM_GROUPS	group for system administration
#
CUPS_USER?=		lp
CUPS_GROUP?=		lp
CUPS_SYSTEM_GROUPS?=	${REAL_ROOT_GROUP}
FILES_SUBST+=		CUPS_USER=${CUPS_USER}
FILES_SUBST+=		CUPS_GROUP=${CUPS_GROUP}
FILES_SUBST+=		CUPS_SYSTEM_GROUPS=${CUPS_SYSTEM_GROUPS:Q}

PKG_GROUPS_VARS+=	CUPS_GROUP CUPS_SYSTEM_GROUPS
PKG_USERS_VARS=		CUPS_USER

BUILD_DEFS+=		CUPS_USER CUPS_GROUP CUPS_SYSTEM_GROUPS VARBASE

DOCDIR=			${PREFIX}/share/doc/cups
EGDIR=			${PREFIX}/share/examples/cups
MIMEDIR=		${PREFIX}/share/cups/mime
PKG_SYSCONFSUBDIR=	cups
CUPS_CONFDIR=		${PKG_SYSCONFDIR}
CUPS_LOGDIR=		${VARBASE}/log/cups
CUPS_REQUESTS=		${VARBASE}/spool/cups
CUPS_CACHE=		${VARBASE}/cache/cups
CUPS_STATEDIR=		${VARBASE}/run/cups

PKG_GROUPS=		${CUPS_GROUP}
PKG_USERS=		${CUPS_USER}:${CUPS_GROUP}
PKG_GECOS.${CUPS_USER}=	Common UNIX Printing System user
PKG_SHELL.${CUPS_USER}=	${SH}

CONF_FILES+=		${EGDIR}/cupsd.conf ${CUPS_CONFDIR}/cupsd.conf
CONF_FILES+=		${EGDIR}/cups-files.conf ${CUPS_CONFDIR}/cups-files.conf
CONF_FILES+=		${EGDIR}/snmp.conf ${CUPS_CONFDIR}/snmp.conf
RCD_SCRIPTS=		cupsd

OWN_DIRS=		${CUPS_CONFDIR}
OWN_DIRS+=		${CUPS_CONFDIR}/interfaces
OWN_DIRS+=		${CUPS_CONFDIR}/ppd
OWN_DIRS+=		${PREFIX}/libexec/cups/driver
OWN_DIRS+=		${CUPS_LOGDIR}
OWN_DIRS+=		${CUPS_STATEDIR}
OWN_DIRS_PERMS=		${CUPS_STATEDIR}/certs ${CUPS_USER} ${CUPS_GROUP} 0711
OWN_DIRS_PERMS+=	${CUPS_CONFDIR}/ssl ${REAL_ROOT_USER} ${CUPS_GROUP} 0700
OWN_DIRS_PERMS+=	${CUPS_REQUESTS} ${REAL_ROOT_USER} ${CUPS_GROUP} 0710
OWN_DIRS_PERMS+=	${CUPS_REQUESTS}/tmp ${REAL_ROOT_USER} ${CUPS_GROUP} 1770
OWN_DIRS_PERMS+=	${CUPS_CACHE} ${REAL_ROOT_USER} ${CUPS_GROUP} 0775
OWN_DIRS_PERMS+=	${CUPS_CACHE}/rss ${REAL_ROOT_USER} ${CUPS_GROUP} 0775

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/cups.pam
SUBST_SED.paths+=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_STAGE.paths=	pre-configure

SUBST_CLASSES+=		rpathfix
SUBST_FILES.rpathfix=	cups-config.in
SUBST_MESSAGE.rpathfix=	Adding rpath to cups-config.
SUBST_SED.rpathfix=	-e 's|@EXPORT_LDFLAGS@|${COMPILER_RPATH_FLAG}${PREFIX}/lib|g'
SUBST_STAGE.rpathfix=	pre-configure

.if !empty(OPSYS:MNetBSD) && !empty(MACHINE_ARCH:Mpowerpc)
SUBST_CLASSES+=		piefix
SUBST_FILES.piefix=	Makedefs.in
SUBST_MESSAGE.piefix=	Removing PIE flags
SUBST_SED.piefix=	-e 's|@PIEFLAGS@||g'
SUBST_STAGE.piefix=	pre-configure
.endif

INSTALLATION_DIRS=	${DOCDIR} ${EGDIR} ${MIMEDIR}
INSTALL_ENV+=		DSTROOT=${DESTDIR}

pre-configure:
.if !empty(CUPS_SYSTEM_GROUPS:M${CUPS_GROUP})
	${ERROR_MSG} "CUPS_SYSTEM_GROUPS may not contain the CUPS_GROUP"
	exit 1
.endif
	cd ${WRKSRC} && aclocal && autoconf

post-extract:
	${CP} ${FILESDIR}/cups.pam ${WRKDIR}/cups.pam

post-install:
	set -e; for file in LICENSE.txt README.md; do			\
		${INSTALL_DATA} ${WRKSRC}/$${file}			\
		     ${DESTDIR}${DOCDIR}/$${file}; \
	done
	${RUN} for file in cupsd.conf cups-files.conf snmp.conf ; do	\
		${INSTALL_DATA} ${WRKSRC}/conf/$${file}			\
			${DESTDIR}${EGDIR}/$${file};			\
	done
	${CHMOD} g-w ${DESTDIR}${PREFIX}/libexec/cups/cgi-bin
.if !empty(PKG_OPTIONS:Mpam)
	${INSTALL_DATA} ${WRKDIR}/cups.pam ${DESTDIR}${EGDIR}
.endif
.if !empty(PKG_OPTIONS:Mdnssd)
	${LN} -sf ${DESTDIR}${PREFIX}/libexec/cups/backend/dnssd ${DESTDIR}${PREFIX}/libexec/cups/backend/mdns
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
