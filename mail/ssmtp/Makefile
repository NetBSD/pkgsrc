# $NetBSD: Makefile,v 1.20 2008/01/18 05:08:30 tnn Exp $
#
# TLS functionality needs testing. Please let me know the result,
# and preferably info about your system.
#
# pkg@pop.707.to
# Toru TAKAMIZU

DISTNAME=	ssmtp_2.61.orig
PKGNAME=	ssmtp-2.61
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/ssmtp/}

MAINTAINER=	pkg@pop.707.to
HOMEPAGE=	http://packages.debian.org/testing/mail/ssmtp.html
COMMENT=	Extremely simple MTA to forward mail to a mail hub

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:S/.orig$//}
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE:Q}

.include "options.mk"

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/ssmtp.conf ${PKG_SYSCONFDIR}/ssmtp.conf
CONF_FILES+=	${EGDIR}/revaliases ${PKG_SYSCONFDIR}/revaliases

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailer.conf ssmtp.c ssmtp.conf ssmtp.8
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,/etc/ssl/certs,${PKG_SYSCONFDIR},g'
SUBST_SED.paths+=	-e 's,/etc/ssmtp,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	@${RM} -rf ${WRKSRC}/RCS
	${CP} ${FILESDIR}/mailer.conf ${WRKDIR}/mailer.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ssmtp.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/revaliases ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mailer.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
