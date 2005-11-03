# $NetBSD: Makefile,v 1.13 2005/11/03 16:59:47 tv Exp $

DISTNAME=	pure-ftpd-1.0.20
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/releases/		\
		ftp://ftp2.fr.pureftpd.org/pub/mirrors/ftp.fr.pureftpd.org/pub/pure-ftpd/releases/ \
		ftp://ftp3.fr.pureftpd.org/pure-ftpd/releases/		\
		ftp://ftp.dk.pureftpd.org/mirrors/pure-ftpd/releases/	\
		ftp://ftp.nl.pureftpd.org/pub/pure-ftpd/releases/	\
		ftp://ftp.fr.pureftpd.org/pub/pure-ftpd/releases/	\
		ftp://ftp.cn.pureftpd.org/pub/pureftpd/pure-ftpd/releases/ \
		${MASTER_SITE_SOURCEFORGE:=pureftpd/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.pureftpd.org/
COMMENT=	FTP daemon with optional SQL support

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-everything	\
			--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Interix"
CONFIGURE_ARGS+=	--with-privsep
.endif

.include "options.mk"

RCD_SCRIPTS=	pure_ftpd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pure-ftpd
	cd ${WRKSRC} &&	\
		${INSTALL_DATA} README README.Authentication-Modules	 \
				README.Configuration-File README.Contrib \
				README.TLS README.Virtual-Users		 \
			${PREFIX}/share/doc/pure-ftpd

.include "../../mk/bsd.pkg.mk"
