# $NetBSD: Makefile,v 1.4 2007/12/02 13:04:15 wiz Exp $

DISTNAME=	syslog-ng-1.6.11
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.balabit.com/downloads/syslog-ng/1.6/src/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.balabit.com/network-security/syslog-ng/
COMMENT=	Syslog-ng tries to fill the gaps original syslogd's were lacking

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
		${PAX} -O -zrf ${WRKSRC}/doc/sgml/syslog-ng.html.tar.gz

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/syslog-ng
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}

	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.spoof ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/syslog-ng.conf.doc ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/syslog-ng.conf.demo ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/syslog-ng.conf.sample ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/syslog-ng.conf.solaris ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/syslog2ng ${PREFIX}/bin

	${INSTALL_DATA} ${WRKSRC}/doc/sgml/syslog-ng.html/*.html ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
