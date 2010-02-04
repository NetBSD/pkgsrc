# $NetBSD: Makefile,v 1.23 2010/02/04 12:34:08 obache Exp $

DISTNAME=		pure-ftpd-1.0.27
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
HOMEPAGE=		http://www.pureftpd.org/project/pure-ftpd
COMMENT=		Secure FTP daemon with optional SQL support

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-everything
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
CONFIGURE_ARGS+=	--without-privsep
.endif

.include "options.mk"

RCD_SCRIPTS=		pure_ftpd
INSTALLATION_DIRS=	share/doc/pure-ftpd

post-install:
	cd ${WRKSRC} &&	\
		${INSTALL_DATA} README README.Authentication-Modules	 \
				README.Configuration-File README.Contrib \
				README.TLS README.Virtual-Users		 \
				README.MySQL README.PGSQL README.LDAP	 \
			${DESTDIR}${PREFIX}/share/doc/pure-ftpd

.include "../../mk/bsd.pkg.mk"
