# $NetBSD: Makefile,v 1.1.1.1 2004/07/21 03:51:11 xtraeme Exp $
#

DISTNAME=		clamsmtp-0.3
CATEGORIES=		mail
MASTER_SITES=		http://memberwebs.com/nielsen/software/clamsmtp/

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://memberwebs.com/nielsen/software/clamsmtp/
COMMENT=		SMTP filter that allows you to check for viruses

BUILD_DEPENDS+=		clamav-[0-9]*:../../mail/clamav

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

RCD_SCRIPTS=		clamsmtpd

MESSAGE_SUBST+=		PKGBASE=${PKGBASE}
MESSAGE_SUBST+=		HOMEPAGE=${HOMEPAGE}

.include "../../mk/bsd.prefs.mk"

FILES_SUBST+=		VARBASE=${VARBASE}
FILES_SUBST+=		CLAMAV_USER=${CLAMAV_USER}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
