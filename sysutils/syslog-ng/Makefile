# $NetBSD: Makefile,v 1.9 2009/12/09 11:12:21 obache Exp $

DISTNAME=	syslog-ng-1.6.12
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/files/syslog-ng/sources/1.6/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.balabit.com/network-security/syslog-ng/
COMMENT=	Syslog-ng tries to fill the gaps original syslogd's were lacking
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pax flex

GNU_CONFIGURE=		YES
RCD_SCRIPTS=		syslogng
PKG_SYSCONFSUBDIR=	syslog-ng

CONFIGURE_ARGS+=	--enable-tcp-wrapper

EGDIR=			${PREFIX}/share/examples/syslog-ng
DOCDIR=			${PREFIX}/share/doc/syslog-ng

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_FILES.conf=	doc/syslog-ng.8 doc/syslog-ng.conf.5 contrib/syslog2ng
SUBST_SED.conf=		-e "s|/etc/syslog-ng|${PKG_SYSCONFDIR}|g"
SUBST_SED.conf+=	-e "s|/usr/bin/awk|${AWK}|g"
SUBST_MESSAGE.conf=	Fixing configuration file paths.

.include "../../mk/bsd.prefs.mk"

.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../sysutils/libol/buildlink3.mk"

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-full-dynamic
.endif

BUILDLINK_API_DEPENDS.libol+=	libol>=0.3.0

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

pre-build:
	cd ${WRKSRC}/doc/sgml && \
		pax -O -zrf ${WRKSRC}/doc/sgml/syslog-ng.html.tar.gz

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	share/doc/html/syslog-ng
INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.spoof ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.doc ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/syslog-ng.conf.demo ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/syslog-ng.conf.sample ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/syslog-ng.conf.solaris ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${DESTDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/doc/sgml/syslog-ng.html/*.html ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
