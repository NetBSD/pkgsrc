# $NetBSD: Makefile,v 1.3 2004/03/26 02:27:44 wiz Exp $
#

DISTNAME=		msmtp-0.5.0
PKGREVISION=		2
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
