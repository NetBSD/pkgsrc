# $NetBSD: Makefile,v 1.27 2020/04/10 23:46:14 khorben Exp $

DISTNAME=	pkg-1.9.99.11
CATEGORIES=	pkgtools
MASTER_SITES=	http://files.etoilebsd.net/pkg/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://wiki.freebsd.org/pkgng
COMMENT=	Package management tool for FreeBSD
LICENSE=	2-clause-bsd

BOOTSTRAP_PKG=	yes
GNU_CONFIGURE=	yes
USE_CWRAPPERS=	no
USE_LANGUAGES=	c

LDFLAGS+=	-pthread
CPPFLAGS+=	-D_LOCALBASE="\"${PREFIX}\""
CPPFLAGS+=	-DPORTSDIR="\"${PKG.portsdir}\""
CPPFLAGS+=	-DDEFAULT_VULNXML_URL="\"http://muscles.dragonflybsd.org/pkgsrc-vuxml/vuln.xml.bz2\""
CFLAGS+=	-DSYSCONFDIR=\"${PKG_SYSCONFDIR}\"

.if defined(DEBUG_PKGNG)
CFLAGS:=		${CFLAGS:N-O2} -ggdb -O0
_STRIPFLAG_INSTALL=	# don't strip
.endif

AUTO_MKDIRS=	yes

EGDIR=		${PREFIX}/share/examples/pkg

CONF_FILES+=	${EGDIR}/bash_completion.d/_pkg.bash \
		${PKG_SYSCONFDIR}/bash_completion.d/_pkg.bash
CONF_FILES+=	${EGDIR}/periodic/daily/411.pkg-backup \
		${PKG_SYSCONFDIR}/periodic/daily/411.pkg-backup
CONF_FILES+=	${EGDIR}/periodic/daily/490.status-pkg-changes \
		${PKG_SYSCONFDIR}/periodic/daily/490.status-pkg-changes
CONF_FILES+=	${EGDIR}/periodic/security/410.pkg-audit \
		${PKG_SYSCONFDIR}/periodic/security/410.pkg-audit
CONF_FILES+=	${EGDIR}/periodic/security/460.pkg-checksum \
		${PKG_SYSCONFDIR}/periodic/security/460.pkg-checksum
CONF_FILES+=	${EGDIR}/periodic/weekly/400.status-pkg \
		${PKG_SYSCONFDIR}/periodic/weekly/400.status-pkg
CONF_FILES+=	${EGDIR}/pkg.conf.sample \
		${PKG_SYSCONFDIR}/pkg.conf

OWN_DIRS=	${PKG_SYSCONFDIR}/bash_completion.d \
		${PKG_SYSCONFDIR}/periodic/daily \
		${PKG_SYSCONFDIR}/periodic/security \
		${PKG_SYSCONFDIR}/periodic/weekly

SUBST_CLASSES+=			manpages-prefix
SUBST_STAGE.manpages-prefix=	pre-install
SUBST_FILES.manpages-prefix=	docs/pkg-install.8 docs/pkg-repo.8
SUBST_FILES.manpages-prefix+=	docs/pkg-search.8 docs/pkg-update.8
SUBST_FILES.manpages-prefix+=	docs/pkg-upgrade.8 docs/pkg.8
SUBST_FILES.manpages-prefix+=	docs/pkg.conf.5
SUBST_SED.manpages-prefix+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.manpages-prefix=	Correct the installation prefix in manual pages.

SUBST_CLASSES+=			pkgconf-prefix
SUBST_STAGE.pkgconf-prefix=	pre-install
SUBST_FILES.pkgconf-prefix=	src/pkg.conf.sample
SUBST_SED.pkgconf-prefix+=	-e "s|/usr/local|${PREFIX}|g"
SUBST_MESSAGE.pkgconf-prefix=	Correct the installation prefix in pkg.conf(5).

SUBST_CLASSES+=		portsdir
SUBST_STAGE.portsdir=	pre-install
SUBST_FILES.portsdir=	src/pkg.conf.sample \
			docs/pkg-create.8 \
			docs/pkg-set.8 \
			docs/pkg-repo.8 \
			docs/pkg.conf.5 \
			docs/pkg-version.8 \
			docs/pkg.8
SUBST_SED.portsdir=	-e "s|/usr/ports|${PKG.portsdir}|g" \
			-e "s|/var/db/pkg|${PKGNG_DBDIR}|g" \
			-e "s|/var/cache/pkg|${VARBASE}/cache/pkgng|g"
SUBST_MESSAGE.portsdir=	Correct reference to FreeBSD portsdir.

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-configure
SUBST_FILES.config=	libpkg/pkg_config.c
SUBST_SED.config=	-e "s|/usr/ports|${PKG.portsdir}|g" \
			-e "s|/var/db/pkg|${PKGNG_DBDIR}|g" \
			-e "s|/var/cache/pkg|${VARBASE}/cache/pkgng|g"
SUBST_MESSAGE.config=	Update pkg(8) defaults.

SUBST_CLASSES+=		vuxml
SUBST_STAGE.vuxml=	pre-configure
SUBST_FILES.vuxml=	libpkg/pkg_audit.c
SUBST_SED.vuxml=	-e "s|https://vuxml.FreeBSD.org/freebsd|http://muscles.dragonflybsd.org/pkgsrc-vuxml/reports|"
SUBST_MESSAGE.vuxml=	Direct audit reports to Pkgsrc vuxml

# Install manpages under ${PKGMANDIR}.
INSTALL_MAKE_FLAGS+=	mandir=${PREFIX:Q}/${PKGMANDIR:Q}

.if defined(PACKAGE_BUILDING) # set by Synth which has custom location, so use default path
PKG.portsdir?=	/usr/pkgsrc
.else
PKG.portsdir?=	${PKGSRCDIR}
.endif

# DragonFly SSL libraries are private.  pkg(8) is the one exception of a userland
# program that is allowed to link to them due to bootstrap reasons
.if exists(/usr/lib/priv/libprivate_ssl.so)
BUILDLINK_PASSTHRU_RPATHDIRS=	/lib/priv
.endif

post-patch:
# DragonFly SSL libraries are private.
.if exists(/usr/lib/priv/libprivate_ssl.so)
	${SED} -i.bak \
		-e 's|lssl|lprivate_ssl|' \
		-e 's|lcrypto|lprivate_crypto|' \
		-e 's|la_rpath = |la_rpath = -R/lib/priv |' \
		${WRKSRC}/libpkg/Makefile.in \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/tests/Makefile.in
	${SED} -i.bak \
		-e '/OS_CFLAGS=/ s|SOURCE|SOURCE -I/usr/include/priv|' \
		-e '/OS_LDFLAGS=/ s|=|="-L/usr/lib/priv -R/lib/priv"|' \
		${WRKSRC}/configure
.endif

post-install:
	${RM} ${DESTDIR}${PREFIX}/sbin/pkg2ng
	${RM} -rf ${DESTDIR}${EGDIR}/periodic
	${MV} ${DESTDIR}${PREFIX}/etc/bash_completion.d \
		${DESTDIR}${EGDIR}/
	${MV} ${DESTDIR}${PREFIX}/etc/periodic \
		${DESTDIR}${EGDIR}/
	${MV} ${DESTDIR}${PREFIX}/etc/pkg.conf.sample \
		${DESTDIR}${EGDIR}/

.include "../../mk/bsd.prefs.mk"

.if defined (PKG_DBDIR)
PKGNG_DBDIR?=	${PKG_DBDIR}
.else
PKGNG_DBDIR?=	${PREFIX}/pkgng-db
.endif

.if ${OPSYS} == "NetBSD"
BUILDLINK_TRANSFORM+=	rm:-Wl,--enable-new-dtags
.endif

.if ${OPSYS} != "FreeBSD" && ${OPSYS} != "DragonFly" && ${OPSYS} != "NetBSD"
.include "../../archivers/libarchive/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
