# $NetBSD: Makefile,v 1.10 2004/10/08 05:39:23 xtraeme Exp $

DISTNAME=		clamsmtp-0.9.5
CATEGORIES=		mail
MASTER_SITES=		http://memberwebs.com/nielsen/software/clamsmtp/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://memberwebs.com/nielsen/software/clamsmtp/
COMMENT=		SMTP filter that allows you to check for viruses

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes
RCD_SCRIPTS=		clamsmtpd

MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}
FILES_SUBST+=		CLAMAV_USER=${CLAMAV_USER}

# Doesn't work with GNU pth (missing required mutex features)
PTHREAD_OPTS+=		require native

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=		${EGDIR}/clamsmtpd.conf \
			${PKG_SYSCONFDIR}/clamsmtpd.conf

INSTALLATION_DIRS=	share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/clamsmtpd.conf ${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
