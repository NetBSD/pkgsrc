# $NetBSD: Makefile,v 1.23 2015/10/29 16:34:13 fhajny Exp $

.include "../../sysutils/syslog-ng/Makefile.common"

CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-stomp
CONFIGURE_ARGS+=	--enable-tcp-wrapper

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-dynamic-linking
CONFIGURE_ARGS+=	--enable-sun-streams
CPPFLAGS+=		-D_XOPEN_SOURCE=600 -D__EXTENSIONS__
.endif

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.doc ${DESTDIR}${DOCDIR}
.for f in syslog-ng.conf.RedHat syslog-ng.conf.SunOS
		${INSTALL_DATA} ${WRKSRC}/contrib/${f} ${DESTDIR}${EGDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${DESTDIR}${PREFIX}/bin

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
