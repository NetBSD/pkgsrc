# $NetBSD: Makefile,v 1.8 2005/04/04 08:45:24 adam Exp $

DISTNAME=	msmtp-1.4.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=msmtp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bcv@hub3.net
HOMEPAGE=	http://msmtp.sourceforge.net/
COMMENT=	SMTP plugin for MUAs

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

EGDIR=		${PREFIX}/share/examples/msmtp

INFO_FILES=	msmtp.info

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc-system.example ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/msmtprc-user.example ${EGDIR}

.include "../../mk/bsd.pkg.mk"
