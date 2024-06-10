# $NetBSD: Makefile,v 1.27 2024/06/10 09:48:18 jperkin Exp $

VERSION=	7.5.0p0
DISTNAME=	opensmtpd-${VERSION}
CATEGORIES=	mail net
MASTER_SITES=	https://www.opensmtpd.org/archives/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.opensmtpd.org/
COMMENT=	The OpenSMTPD mail transfer agent, a replacement for sendmail
LICENSE=	isc AND modified-bsd AND 2-clause-bsd

BUILD_DEFS+=	VARBASE
SMTPD_HOME=	${VARBASE}/smtpd/empty

GNU_CONFIGURE=	yes
USE_DB185=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	awk pkg-config yacc
USE_TOOLS+=	automake aclocal autoheader autoconf

CHECK_BUILTIN.openssl:= yes
.include "../../security/openssl/buildlink3.mk"
CHECK_BUILTIN.openssl:= no
.if ${USE_BUILTIN.openssl:U:tl} != yes
DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
.endif

PLIST_SRC=	PLIST.common

CFLAGS.SunOS+=	-D__EXTENSIONS__

PKG_GROUPS=		_smtpd _smtpq
PKG_USERS=		_smtpd:_smtpd _smtpq:_smtpq
PKG_GECOS._smtpd=	OpenSMTPD Daemon
PKG_GECOS._smtpq=	OpenSMTPD Queue
.for id in _smptd _smtpq
PKG_HOME.${id}=		${SMTPD_HOME}
PKG_SHELL.${id}=	${NOLOGIN}
.endfor

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	smtpd

CONFIGURE_ENV+=		MANTYPE=man
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libssl=${SSLBASE:Q}
CONFIGURE_ARGS+=	--with-path-CAfile=${SSLCERTS}/ca-certificates.crt
CONFIGURE_ARGS+=	--with-path-empty=${SMTPD_HOME}
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-path-mbox=${VARBASE}/spool/mail
.else
CONFIGURE_ARGS+=	--with-path-mbox=${VARBASE}/mail
.endif
CONFIGURE_ARGS+=	--with-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-table-db
CONFIGURE_ARGS+=	--with-pie

.include "options.mk"

EGDIR=			${PREFIX}/share/examples/opensmtpd
DOCDIR=			${PREFIX}/share/doc/opensmtpd
CONF_FILES+=		${EGDIR}/smtpd.conf ${PKG_SYSCONFDIR}/smtpd.conf
CONF_FILES+=		${EGDIR}/aliases ${PKG_SYSCONFDIR}/aliases

OWN_DIRS+=	${SMTPD_HOME} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700

INSTALLATION_DIRS+=	share/examples/${PKGBASE}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

RCD_SCRIPTS=	opensmtpd

SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} _smtpq 2555
SPECIAL_PERMS+=		sbin/smtpctl ${SETUID_ROOT_PERMS}

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	mailer.conf README.pkgsrc
SUBST_VARS.pkgsrc=	PKG_SYSCONFDIR PREFIX RCD_SCRIPTS_DIR VARBASE
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders.

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing hard-coded paths.
SUBST_FILES.paths+=	configure mk/smtpd/Makefile.am usr.sbin/smtpd/smtpd.conf \
			usr.sbin/smtpd/smtpd.h usr.sbin/smtpd/smtpd.8 \
			usr.sbin/smtpd/smtpd.conf.5 usr.sbin/smtpd/aliases.5 \
			usr.sbin/smtpd/makemap.8 usr.sbin/smtpd/newaliases.8
SUBST_SED.paths+=	-e "s:/etc/mail:${PKG_SYSCONFDIR}:g"
SUBST_SED.paths+=	-e "s:/usr/local/etc:${PKG_SYSCONFDIR}:g"
SUBST_SED.paths+=	-e "s:/usr/local/lib:${PREFIX}/lib:g"
SUBST_SED.paths+=	-e "s:/usr/local/libexec:${PREFIX}/libexec:g"
SUBST_SED.paths+=	-e "s:@EXAMPLE_DIR@:${EGDIR}:g"
SUBST_SED.paths+=	-e "s:/etc/ssl:${SSLDIR}:g"

MESSAGE_SUBST+=		DOCDIR=${DOCDIR:Q}

post-extract:
.for f in mailer.conf README.pkgsrc
	cp ${FILESDIR}/${f} ${WRKSRC}
.endfor

pre-configure:
	cd ${WRKSRC} && ${PREFIX}/bin/libtoolize --copy --force
	cd ${WRKSRC} && ${TOOLS_CMD.aclocal}
	cd ${WRKSRC} && ${TOOLS_CMD.autoconf}
	cd ${WRKSRC} && ${TOOLS_CMD.autoheader}
	cd ${WRKSRC} && ${TOOLS_CMD.automake} --foreign --add-missing --copy

.PHONY: doc-install
doc-install:
	${INSTALL_DATA} ${WRKSRC}/etc/aliases ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README.pkgsrc ${DESTDIR}${DOCDIR}

.if ${OPSYS} == "Linux"
.  include "../../devel/libbsd/buildlink3.mk"
.endif
.include "../../databases/db5/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libasr/buildlink3.mk"
.include "../../security/libretls/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
