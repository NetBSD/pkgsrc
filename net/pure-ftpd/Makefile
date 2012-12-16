# $NetBSD: Makefile,v 1.30 2012/12/16 01:52:30 obache Exp $

DISTNAME=	pure-ftpd-1.0.35
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/releases/ \
		http://download.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp2.fr.pureftpd.org/pub/mirrors/ftp.fr.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp3.fr.pureftpd.org/pure-ftpd/releases/ \
		ftp://ftp.dk.pureftpd.org/mirrors/pure-ftpd/releases/ \
		ftp://ftp.nl.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.fr.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp.cn.pureftpd.org/pub/pureftpd/pure-ftpd/releases/ \
		${MASTER_SITE_SOURCEFORGE:=pureftpd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.pureftpd.org/project/pure-ftpd
COMMENT=	Secure FTP daemon with optional SQL support
LICENSE=	modified-bsd

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

RCD_SCRIPTS=		pure_ftpd pure_uploadscript
INSTALLATION_DIRS=	share/doc/pure-ftpd

post-install:
	cd ${WRKSRC} &&	\
		${INSTALL_DATA} README README.Authentication-Modules	 \
				README.Configuration-File README.Contrib \
				README.TLS README.Virtual-Users		 \
				README.MySQL README.PGSQL README.LDAP	 \
			${DESTDIR}${PREFIX}/share/doc/pure-ftpd

.include "../../mk/bsd.pkg.mk"
