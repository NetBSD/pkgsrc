# $NetBSD: Makefile,v 1.9 2010/11/13 21:08:59 shattered Exp $

DISTNAME=	proxsmtp-1.0
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://memberwebs.com/stef/software/proxsmtp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://memberwebs.com/stef/software/proxsmtp/
COMMENT=	SMTP proxy content filter

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONF_FILES=	${EGDIR}/proxsmtpd.conf ${PKG_SYSCONFDIR}/proxsmtpd.conf
RCD_SCRIPTS=	proxsmtpd

INSTALLATION_DIRS=	${EGDIR}

.include "../../mk/pthread.buildlink3.mk"

post-install:
	for file in							\
		doc/proxsmtpd.conf					\
		scripts/add_header.sh					\
		scripts/spamassassin.sh;				\
	do								\
		${INSTALL_DATA} ${WRKSRC}/$$file ${DESTDIR}${EGDIR};	\
	done

.include "../../mk/bsd.pkg.mk"
