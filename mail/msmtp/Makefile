# $NetBSD: Makefile,v 1.5 2004/06/20 21:05:02 xtraeme Exp $
#

DISTNAME=		msmtp-1.0.0
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=msmtp/}

MAINTAINER=		bcv@hub3.net
HOMEPAGE=		http://msmtp.sourceforge.net/
COMMENT=		SMTP plugin for MUAs

USE_BUILDLINK3=		YES
GNU_CONFIGURE=    	YES

EGDIR=                  ${PREFIX}/share/examples/msmtp

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc.example ${EGDIR}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
