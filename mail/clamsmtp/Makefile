# $NetBSD: Makefile,v 1.47 2018/01/22 15:50:37 fhajny Exp $

DISTNAME=		clamsmtp-1.10
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://thewalter.net/stef/software/clamsmtp/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://thewalter.net/stef/software/clamsmtp/
COMMENT=		SMTP filter that allows you to check for viruses
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes
RCD_SCRIPTS=		clamsmtpd

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE:Q}
FILES_SUBST+=		CLAMAV_USER=${CLAMAV_USER}
FILES_SUBST+=		CLAMAV_GROUP=${CLAMAV_GROUP}

# Doesn't work with GNU pth (missing required mutex features)
PTHREAD_OPTS+=		require native

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/clamsmtpd.conf \
			${PKG_SYSCONFDIR}/clamsmtpd.conf

INSTALLATION_DIRS=	share/examples/${PKGBASE}

PKG_USERS_VARS=		CLAMAV_USER
PKG_GROUPS_VARS=	CLAMAV_GROUP
PKG_GROUPS+=		${CLAMAV_GROUP}
PKG_USERS+=		${CLAMAV_USER}:${CLAMAV_GROUP}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/virus_action.sh ${DESTDIR}${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
