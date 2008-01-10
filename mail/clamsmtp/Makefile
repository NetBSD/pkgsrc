# $NetBSD: Makefile,v 1.38 2008/01/10 07:47:29 martti Exp $

DISTNAME=		clamsmtp-1.9
#PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://memberwebs.com/stef/software/clamsmtp/

MAINTAINER=		martti@NetBSD.org
HOMEPAGE=		http://memberwebs.com/stef/software/clamsmtp/
COMMENT=		SMTP filter that allows you to check for viruses
#LICENSE=		modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
RCD_SCRIPTS=		clamsmtpd

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}
FILES_SUBST+=		CLAMAV_USER=${CLAMAV_USER}

# Doesn't work with GNU pth (missing required mutex features)
PTHREAD_OPTS+=		require native

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/clamsmtpd.conf \
			${PKG_SYSCONFDIR}/clamsmtpd.conf

INSTALLATION_DIRS=	share/examples/${PKGBASE}

PKG_USERS_VARS=		CLAMAV_USER

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/virus_action.sh ${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
