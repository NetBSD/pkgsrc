# $NetBSD: Makefile,v 1.19 2012/09/15 10:06:32 obache Exp $

VERS=		3.2.4
DISTNAME=	syslog-ng_${VERS}
PKGNAME=	syslog-ng-${VERS}
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/open-source-edition/${VERS}/source/
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.balabit.com/network-security/syslog-ng/
COMMENT=	Syslog-ng tries to fill the gaps original syslogd's were lacking
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	flex pkg-config gmake awk:run
USE_LIBTOOL=	YES

GNU_CONFIGURE=		YES
RCD_SCRIPTS=		syslogng
PKG_SYSCONFSUBDIR=	syslog-ng

CONFIGURE_ARGS+=	--enable-tcp-wrapper
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db/syslog-ng
CONFIGURE_ARGS+=	--with-pidfile-dir=${VARBASE}/run
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

REPLACE_AWK+=		contrib/syslog2ng

EGDIR=			${PREFIX}/share/examples/syslog-ng
DOCDIR=			${PREFIX}/share/doc/syslog-ng

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

OWN_DIRS+=	${VARBASE}/db/syslog-ng

BUILD_DEFS+=	VARBASE

CONF_FILES+=	${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/modules.conf
CONF_FILES+=	${EGDIR}/scl.conf ${PKG_SYSCONFDIR}/scl.conf
CONF_FILES+=	${EGDIR}/syslog-ng.conf ${PKG_SYSCONFDIR}/syslog-ng.conf

SUBST_CLASSES+=		unamepath
SUBST_STAGE.unamepath=	post-configure
SUBST_FILES.unamepath=	contrib/syslog2ng
SUBST_VARS.unamepath=	UNAME

.include "../../mk/bsd.prefs.mk"

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../sysutils/eventlog/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=0.9.8
.include "../../security/openssl/buildlink3.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-full-dynamic
CONFIGURE_ARGS+=	--enable-sun-streams
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.syslog-ng
PKG_SUPPORTED_OPTIONS=	syslogng-spoof

PKG_OPTIONS_LEGACY_OPTS+=	spoof:syslogng-spoof

.include "../../mk/bsd.options.mk"

#
# spoof the original source address of forwarded syslog packets
#
.if !empty(PKG_OPTIONS:Msyslogng-spoof)
CONFIGURE_ARGS+=	--enable-spoof-source
.include "../../devel/libnet11/buildlink3.mk"
.endif

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.doc ${DESTDIR}${DOCDIR}
	for f in syslog-ng.conf.sample syslog-ng.conf.solaris syslog-ng.service\	; do \
		${INSTALL_DATA} ${WRKSRC}/doc/examples/$${f} ${DESTDIR}${EGDIR};\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
