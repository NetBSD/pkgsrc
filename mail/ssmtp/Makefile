# $NetBSD: Makefile,v 1.37 2023/10/24 22:09:50 wiz Exp $
#
# TLS functionality needs testing. Please let me know the result,
# and preferably info about your system.
#
# Toru TAKAMIZU

DISTNAME=	ssmtp_2.64.orig
EXTRACT_SUFX=	.tar.bz2
PKGNAME=	ssmtp-2.64
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/ssmtp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/stable/mail/ssmtp
COMMENT=	Extremely simple MTA to forward mail to a mail hub
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:S/.orig$//}
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

.include "options.mk"

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/ssmtp.conf ${PKG_SYSCONFDIR}/ssmtp.conf
CONF_FILES+=		${EGDIR}/revaliases ${PKG_SYSCONFDIR}/revaliases

MAKE_DIRS+=		${PKG_SYSCONFDIR}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf ssmtp.c ssmtp.conf ssmtp.8
SUBST_VARS.paths=	PREFIX
SUBST_SED.paths+=	-e 's,/etc/ssl/certs,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,/etc/ssmtp,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS+=	${EGDIR}

MAKE_FLAGS+=		prefix=${DESTDIR}${PREFIX}
MAKE_FLAGS+=		mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

post-extract:
	@${RM} -rf ${WRKSRC}/RCS
	${CP} ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/ssmtp.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/revaliases ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
