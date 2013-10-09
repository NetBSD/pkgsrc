# $NetBSD: Makefile,v 1.44 2013/10/09 14:37:50 taca Exp $

DISTNAME=		clamsmtp-1.10
#PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://thewalter.net/stef/software/clamsmtp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://thewalter.net/stef/software/clamsmtp/
COMMENT=		SMTP filter that allows you to check for viruses
LICENSE=		modified-bsd

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
RCD_SCRIPTS=		clamsmtpd

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}
FILES_SUBST+=		CLAMAV_USER=${CLAMAV_USER}

# Doesn't work with GNU pth (missing required mutex features)
PTHREAD_OPTS+=		require native

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/clamsmtpd.conf \
			${PKG_SYSCONFDIR}/clamsmtpd.conf

INSTALLATION_DIRS=	share/examples/${PKGBASE}

PKG_USERS_VARS=		CLAMAV_USER

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/virus_action.sh ${DESTDIR}${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
