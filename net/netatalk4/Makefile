# $NetBSD: Makefile,v 1.33 2026/02/19 14:52:32 hauke Exp $

GITHUB_PROJECT=	netatalk
GITHUB_TAG=	refs/tags/${DISTNAME}
DISTNAME=	netatalk-${PKGVER:C/\./-/g}

PKGNAME=	${DISTNAME:C/-[0-9].*$//}-${PKGVER}
PKGVER=		4.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Netatalk/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://netatalk.io/
COMMENT=	AFP file and AppleTalk print services
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

USE_TOOLS+=		pkg-config perl
TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt

PKG_SYSCONFSUBDIR=	netatalk

BUILD_DEFS+=		VARBASE

EGDIR=			share/examples/netatalk
CONF_FILES+=		${EGDIR}/afp.conf	${PKG_SYSCONFDIR}/afp.conf
CONF_FILES+=		${EGDIR}/extmap.conf	${PKG_SYSCONFDIR}/extmap.conf

CONFLICTS=		netatalk22-[0-9]* netatalk30-[0-9]* netatalk3-[0-9]*
CONFLICTS+=		netatalk-[0-9]* netatalk-asun-[0-9]* netatalk-umich-[0-9]*

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=		netatalk
RCD_SCRIPT_SRC.netatalk= ${WRKSRC}/output/distrib/initscripts/netatalk

SMF_SRCDIR=		${WRKSRC}/distrib/initscripts
SMF_METHODS=		netatalk_smf
SMF_MANIFEST=		netatalk.xml

.if ${OPSYS} == "NetBSD"
# See PR lib/50485
MESON_ARGS+=		-Dwith-dtrace=false
.endif

BDB_ACCEPTED=		db4 db5
# Build script expects exactly major dot minor
MESON_ARGS+=		-Dwith-bdb-version=${BUILDLINK_ABI_DEPENDS.${BDB_TYPE}:C/^.*>=//:R}
MESON_ARGS+=		-Dwith-bdb-path=${BDBBASE}

MESON_ARGS+=		-Dwith-tcp-wrappers=true
MESON_ARGS+=		-Dwith-statedir-path=${VARBASE}/db
MESON_ARGS+=		-Dwith-init-hooks=false

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD"
MESON_BINARIES+=	service
MESON_BINARY.service=	/usr/sbin/service
.endif

LDFLAGS.FreeBSD+=	-lpthread

# Meson will look for perl(1), but then substitute the buildlink path
# into scripts, so replace manually
SUBST_CLASSES+=		perlpath
SUBST_STAGE.perlpath=	pre-configure
SUBST_FILES.perlpath+=	contrib/bin_utils/macusers.pl
SUBST_FILES.perlpath+=	contrib/bin_utils/afpstats.pl
SUBST_FILES.perlpath+=	contrib/bin_utils/addump.pl
SUBST_FILES.perlpath+=	contrib/bin_utils/asip-status.pl
SUBST_SED.perlpath=	-e 's|@PERL@|${PERL5}|g'

# Keep Meson from installing rc.d files
SUBST_CLASSES+=		init
SUBST_STAGE.init=	pre-configure
SUBST_FILES.init+=	distrib/initscripts/meson.build
SUBST_SED.init+=	-E -e 's|(install): true|\1: false|g'

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	pre-configure
SUBST_FILES.varbase+=	meson.build
SUBST_SED.varbase+=	-e 's,/var/,${VARBASE}/,g'

MAKE_DIRS+=		${PKG_SYSCONFDIR}/msg
OWN_DIRS+=		${VARBASE}/db/netatalk/CNID ${REAL_ROOT_USER} ${REAL_ROOT_GROUP}

PLIST_VARS+=		ea
.if ${OPSYS} == "SunOS" || ${OPSYS} == "DragonFly" || ${OPSYS} == "Linux" || \
	(${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 070000) || \
	${OPSYS} == "FreeBSD"
PLIST.ea=		yes
.endif

# appletalk
.for atbin in aecho getzones nbplkup nbprgstr nbpunrgstr pap papstatus rtmpqry
PRINT_PLIST_AWK+=	{ gsub(/^bin\/${atbin}$$/, "$${PLIST.appletalk}&"); }
.endfor
.for atsbin in a2boot atalkd macipgw papd timelord
PRINT_PLIST_AWK+=	{ gsub(/^sbin\/${atsbin}$$/, "$${PLIST.appletalk}&"); }
.endfor
.for athdr in aarp at at_var ddp ddp_var endian phase2
PRINT_PLIST_AWK+=	{ gsub(/^include\/netatalk\/${athdr}\.h$$/, "$${PLIST.appletalk}&"); }
.endfor
.for atman1 in aecho getzones nbp nbplkup nbprgstr nbpunrgstr pap rtmpqry
PRINT_PLIST_AWK+=	{ gsub(/^man\/man1\/${atman1}\.1$$/, "$${PLIST.appletalk}&"); }
.endfor
.for atman5 in atalkd.conf papd.conf macipgw.conf
PRINT_PLIST_AWK+=	{ gsub(/^man\/man5\/${atman5}\.5$$/, "$${PLIST.appletalk}&"); }
.endfor
.for atman8 in a2boot atalkd macipgw papd papstatus timelord
PRINT_PLIST_AWK+=	{ gsub(/^man\/man8\/${atman8}\.8$$/, "$${PLIST.appletalk}&"); }
.endfor
PRINT_PLIST_AWK+=	{ gsub(/^share\/doc\/netatalk\/APPLETALK.txt$$/, "$${PLIST.appletalk}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^share\/examples\/netatalk\/(atalk|pap)d\.conf$$/, "$${PLIST.appletalk}&"); }

# ea
PRINT_PLIST_AWK+=	{ gsub(/^bin\/ad$$/, "$${PLIST.ea}&"); }

# gssapi
PRINT_PLIST_AWK+=	{ gsub(/^lib\/netatalk\/uams_gss\.so$$/, "$${PLIST.gssapi}&"); }

# ldap
PRINT_PLIST_AWK+=	{ gsub(/^share\/examples\/netatalk\/afp_ldap\.conf$$/, "$${PLIST.ldap}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^bin\/afpldaptest$$/, "$${PLIST.ldap}&"); }

# pam
PRINT_PLIST_AWK+=	{ gsub(/^lib\/netatalk\/uams_.*pam\.so$$/, "$${PLIST.pam}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^share\/examples\/netatalk\/netatalk\.pam$$/, "$${PLIST.pam}&"); }

# spotlight
PRINT_PLIST_AWK+=	{ gsub(/^share\/dbus-1\/netatalk-dbus\.conf$$/, "$${PLIST.spotlight}&"); }
PRINT_PLIST_AWK+=	{ gsub(/^share\/examples\/netatalk\/dbus-session\.conf$$/, "$${PLIST.spotlight}&"); }

.include "options.mk"

INSTALLATION_DIRS+=	${EGDIR}

post-configure:
	${CP} ${FILESDIR}/netatalk_smf.sh ${SMF_SRCDIR}

post-install:
	rm -rf ${DESTDIR}${PREFIX}/share/doc/netatalk/developer
	rm -rf ${DESTDIR}${PREFIX}/share/doc/netatalk/manual
	chmod -w ${DESTDIR}${PREFIX}/bin/afppasswd
	${INSTALL_DATA} ${WRKSRC}/output/config/afp.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/afp.conf
	${INSTALL_DATA} ${WRKSRC}/config/extmap.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/extmap.conf
.if !empty(PKG_OPTIONS:Mappletalk)
	${INSTALL_DATA} ${WRKSRC}/config/atalkd.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/atalkd.conf
	${INSTALL_DATA} ${WRKSRC}/config/papd.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/papd.conf
.endif
.if !empty(PKG_OPTIONS:Mspotlight)
	${INSTALL_DATA} ${WRKSRC}/output/config/dbus-session.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/dbus-session.conf
.endif
.if !empty(PKG_OPTIONS:Mpam)
	${INSTALL_DATA} ${WRKSRC}/output/config/pam/netatalk \
		${DESTDIR}${PREFIX}/${EGDIR}/netatalk.pam
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/iniparser/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=        libevent>=2
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libbstring/buildlink3.mk"
.include "../../security/cracklib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../textproc/cmark-gfm/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
