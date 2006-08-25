# $NetBSD: Makefile,v 1.25 2006/08/25 06:31:00 xtraeme Exp $

DISTNAME=		clamsmtp-1.7
CATEGORIES=		mail
MASTER_SITES=		http://memberwebs.com/nielsen/software/clamsmtp/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://memberwebs.com/nielsen/software/clamsmtp/
COMMENT=		SMTP filter that allows you to check for viruses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
RCD_SCRIPTS=		clamsmtpd

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}
FILES_SUBST+=		CLAMAV_USER=${CLAMAV_USER:Q}

# Doesn't work with GNU pth (missing required mutex features)
PTHREAD_OPTS+=		require native

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/clamsmtpd.conf \
			${PKG_SYSCONFDIR}/clamsmtpd.conf

INSTALLATION_DIRS=	share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/virus_action.sh ${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
