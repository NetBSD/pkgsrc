# $NetBSD: Makefile,v 1.7 2005/01/19 15:30:25 adam Exp $

DISTNAME=	msmtp-1.2.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=msmtp/}

MAINTAINER=	bcv@hub3.net
HOMEPAGE=	http://msmtp.sourceforge.net/
COMMENT=	SMTP plugin for MUAs

USE_BUILDLINK3=		yes
GNU_CONFIGURE=    	yes

EGDIR=                  ${PREFIX}/share/examples/msmtp

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc.example ${EGDIR}

.include "../../mk/bsd.pkg.mk"
