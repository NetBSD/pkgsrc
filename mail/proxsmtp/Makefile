# $NetBSD: Makefile,v 1.1.1.1 2004/12/02 04:08:18 jlam Exp $

DISTNAME=	proxsmtp-0.6
CATEGORIES=	mail
MASTER_SITES=	http://memberwebs.com/nielsen/software/proxsmtp/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://memberwebs.com/nielsen/software/proxsmtp/
COMMENT=	SMTP proxy content filter

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_PKGINSTALL=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/proxsmtpd.conf ${PKG_SYSCONFDIR}/proxsmtpd.conf
RCD_SCRIPTS=	proxsmtpd

INSTALLATION_DIRS=      share/examples/${PKGBASE}

.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	for file in							\
		doc/proxsmtpd.conf					\
		scripts/add_header.sh					\
		scripts/spamassassin.sh;				\
	do								\
		${INSTALL_DATA} ${WRKSRC}/$$file ${EGDIR};		\
	done

.include "../../mk/bsd.pkg.mk"
