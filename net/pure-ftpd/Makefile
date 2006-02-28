# $NetBSD: Makefile,v 1.20 2006/02/28 14:06:40 ghen Exp $

DISTNAME=		pure-ftpd-1.0.21
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.pureftpd.org/pub/pure-ftpd/releases/
MASTER_SITES+=		http://download.pureftpd.org/pub/pure-ftpd/releases/
MASTER_SITES+=		ftp://ftp2.fr.pureftpd.org/pub/mirrors/ftp.fr.pureftpd.org/pub/pure-ftpd/releases/
MASTER_SITES+=		ftp://ftp3.fr.pureftpd.org/pure-ftpd/releases/
MASTER_SITES+=		ftp://ftp.dk.pureftpd.org/mirrors/pure-ftpd/releases/
MASTER_SITES+=		ftp://ftp.nl.pureftpd.org/pub/pure-ftpd/releases/
MASTER_SITES+=		ftp://ftp.fr.pureftpd.org/pub/pure-ftpd/releases/
MASTER_SITES+=		ftp://ftp.cn.pureftpd.org/pub/pureftpd/pure-ftpd/releases/
MASTER_SITES+=		${MASTER_SITE_SOURCEFORGE:=pureftpd/}

MAINTAINER=		dawszy@arhea.net
HOMEPAGE=		http://www.pureftpd.org/
COMMENT=		Secure FTP daemon with optional SQL support

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-everything
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Interix"
CONFIGURE_ARGS+=	--with-privsep
.endif

.include "options.mk"

RCD_SCRIPTS=		pure_ftpd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pure-ftpd
	cd ${WRKSRC} &&	\
		${INSTALL_DATA} README README.Authentication-Modules	 \
				README.Configuration-File README.Contrib \
				README.TLS README.Virtual-Users		 \
				README.MySQL README.PGSQL README.LDAP	 \
			${PREFIX}/share/doc/pure-ftpd

.include "../../mk/bsd.pkg.mk"
