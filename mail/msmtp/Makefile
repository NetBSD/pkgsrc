# $NetBSD: Makefile,v 1.6 2004/09/19 13:02:00 wiz Exp $
#

DISTNAME=		msmtp-1.2.3
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=msmtp/}

MAINTAINER=		bcv@hub3.net
HOMEPAGE=		http://msmtp.sourceforge.net/
COMMENT=		SMTP plugin for MUAs

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=		YES
GNU_CONFIGURE=    	YES

EGDIR=                  ${PREFIX}/share/examples/msmtp

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc.example ${EGDIR}

.include "../../mk/bsd.pkg.mk"
