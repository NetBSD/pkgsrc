# $NetBSD: Makefile,v 1.12 2011/09/27 16:27:07 bouyer Exp $

VERS=		3.2.4
DISTNAME=	syslog-ng_${VERS}
PKGNAME=	syslog-ng-${VERS}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/open-source-edition/${VERS}/source/
WRKSRC=		${WRKDIR}/syslog-ng-${VERS}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.balabit.com/network-security/syslog-ng/
COMMENT=	Syslog-ng tries to fill the gaps original syslogd's were lacking
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	flex pkg-config gmake

GNU_CONFIGURE=		YES
RCD_SCRIPTS=		syslogng
PKG_SYSCONFSUBDIR=	syslog-ng

CONFIGURE_ARGS+=	--enable-tcp-wrapper
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/db/syslog-ng
CONFIGURE_ARGS+=	--with-pidfile=${VARBASE}/run

EGDIR=			${PREFIX}/share/examples/syslog-ng
DOCDIR=			${PREFIX}/share/doc/syslog-ng

.include "../../mk/bsd.prefs.mk"

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../sysutils/eventlog/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-full-dynamic
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
