# $NetBSD: Makefile,v 1.14 2014/02/12 23:18:40 tron Exp $
#

DISTNAME=		monit-5.6
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://mmonit.com/monit/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mmonit.com/monit/
COMMENT=		Utility for monitoring processes, files, directories and devices
LICENSE=		gnu-agpl-v3

# no platform specific code yet
NOT_FOR_PLATFORM+=	BSDOS-*-* DragonFly-*-* Interix-*-* IRIX-*-* OSF1-*-*

USE_TOOLS+=		gmake gzcat flex yacc
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.monit
PKG_SUPPORTED_OPTIONS=	ssl
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Mssl)
CONFIGURE_ARGS+=	--without-ssl
.endif
CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
.if ${OPSYS} == "SunOS" && ${ABI} == "32"
CONFIGURE_ARGS+=	--without-largefiles
.endif
PKG_SYSCONFSUBDIR=	monit

RCD_SCRIPTS=		monit
RCD_SCRIPT_SRC.monit=	${FILESDIR}/monit-rc-script.sh

CONF_FILES=		${EGDIR}/monitrc.sample ${PKG_SYSCONFDIR}/monitrc
CONF_FILES_MODE=	0600

OWN_DIRS+=		${PKG_SYSCONFDIR}/monit.d

DOC_SUBDIR=		share/docs/monit
DOCDIR=			${PREFIX}/${DOC_SUBDIR}
EG_SUBDIR=		share/examples/monit
EGDIR=			${PREFIX}/${EG_SUBDIR}

M_DOCFILES=		CHANGES COPYING README
M_DOCFILES+=		doc/PLATFORMS

SUBST_CLASSES+=		monit
SUBST_STAGE.monit=	pre-configure
SUBST_MESSAGE.monit=	Setting daemon interval
SUBST_FILES.monit=	monitrc
SUBST_SED.monit=	-e "s|^\# *set *daemon|set daemon|"
SUBST_SED.monit+=	-e "s|include */etc/monit.d|include ${PKG_SYSCONFDIR}/monit.d|"

# Perform configure substitutions on monit.1
post-configure:
	cd ${WRKSRC} && mv monit.1 monit.1.in && ./config.status --file=monit.1

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
.for f in ${M_DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/monitrc ${DESTDIR}${EGDIR}/monitrc.sample
	${INSTALL_DATA} ${WRKSRC}/contrib/monit.service ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/monit.upstart ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/monitrc-gentoo ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/contrib/rc.monit ${DESTDIR}${EGDIR}/

.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
