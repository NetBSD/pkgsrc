# $NetBSD: Makefile,v 1.4 2004/08/03 08:23:58 jlam Exp $

DISTNAME=		clamsmtp-0.4
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

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
