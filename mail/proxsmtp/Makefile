# $NetBSD: Makefile,v 1.5 2005/12/17 05:20:22 jlam Exp $

DISTNAME=	proxsmtp-1.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://memberwebs.com/nielsen/software/proxsmtp/

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://memberwebs.com/nielsen/software/proxsmtp/
COMMENT=	SMTP proxy content filter

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
