# $NetBSD: Makefile,v 1.1.1.1 2003/09/19 09:24:29 wiz Exp $
#

DISTNAME=		msmtp-0.5.0
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=msmtp/}

MAINTAINER=		bcv@hub3.net
HOMEPAGE=		http://msmtp.sourceforge.net/
COMMENT=		SMTP plugin for MUAs

USE_BUILDLINK2=		yes

EGDIR=                  ${PREFIX}/share/examples/msmtp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msmtp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/msmtp.1 ${PREFIX}/man/man1

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/msmtprc.example ${EGDIR}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
