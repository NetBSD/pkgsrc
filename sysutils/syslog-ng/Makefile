# $NetBSD: Makefile,v 1.46 2023/10/24 22:11:14 wiz Exp $

PKGREVISION= 2
.include "../../sysutils/syslog-ng/Makefile.common"

CONFIGURE_ARGS+=	--enable-stomp
CONFIGURE_ARGS+=	--enable-tcp-wrapper
CONFIGURE_ARGS+=	--with-jsonc=system

CONFIGURE_ARGS.SunOS+=	--enable-dynamic-linking
CONFIGURE_ARGS.SunOS+=	--enable-sun-streams
CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE=600 -D__EXTENSIONS__

.include "options.mk"

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	syslog-ng
EGDIR=			${PREFIX}/share/examples/syslog-ng
DOCDIR=			${PREFIX}/share/doc/syslog-ng

OWN_DIRS+=		${VARBASE}/db/syslog-ng
CONF_FILES+=		${EGDIR}/scl.conf ${PKG_SYSCONFDIR}/scl.conf
CONF_FILES+=		${EGDIR}/syslog-ng.conf ${PKG_SYSCONFDIR}/syslog-ng.conf

RCD_SCRIPTS=		syslogng

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}
INSTALL_TARGET=		install
INSTALLATION_DIRS=	bin ${DOCDIR} ${EGDIR}

PLIST_VARS+=		systemd

.if exists(/bin/systemd)
PLIST.systemd=		yes
.endif

PKGCONFIG_OVERRIDE+=	libtest/syslog-ng-test.pc.in
PKGCONFIG_OVERRIDE+=	syslog-ng-native-connector.pc.in
PKGCONFIG_OVERRIDE+=	syslog-ng.pc.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.doc ${DESTDIR}${DOCDIR}
.for f in syslog-ng.conf.HP-UX syslog-ng.conf.RedHat syslog-ng.conf.SunOS
	${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${DESTDIR}${EGDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${DESTDIR}${PREFIX}/bin

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
