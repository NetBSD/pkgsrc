# $NetBSD: Makefile,v 1.2 2004/12/04 20:37:47 jlam Exp $

DISTNAME=	proxsmtp-1.0
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
