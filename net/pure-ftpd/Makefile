# $NetBSD: Makefile,v 1.9 2004/10/03 00:17:57 tv Exp $

DISTNAME=	pure-ftpd-1.0.19
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

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-everything	\
			--with-privsep		\
			--sysconfdir=${PKG_SYSCONFDIR}

.include "../../mk/bsd.prefs.mk"

.if !empty(PURE_FTPD_USE_MYSQL:M[Yy][Ee][Ss])
.  include "../../databases/mysql-client/buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
CPPFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql
BUILD_DEFS+=		PURE_FTPD_USE_MYSQL
.endif

.if !empty(PURE_FTPD_USE_PGSQL:M[Yy][Ee][Ss])
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
BUILD_DEFS+=		PURE_FTPD_USE_PGSQL
.endif

.if !empty(PURE_FTPD_USE_TLS:M[Yy][Ee][Ss])
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tls
BUILD_DEFS+=		PURE_FTPD_USE_TLS
.endif

.if !empty(PURE_FTPD_USE_VIRTUAL_CHROOT:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-virtualchroot
BUILD_DEFS+=		PURE_FTPD_USE_VIRTUAL_CHROOT
.endif

RCD_SCRIPTS=	pure_ftpd

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pure-ftpd
	cd ${WRKSRC} &&	\
		${INSTALL_DATA} README README.Authentication-Modules	 \
				README.Configuration-File README.Contrib \
				README.TLS README.Virtual-Users		 \
			${PREFIX}/share/doc/pure-ftpd

.include "../../mk/bsd.pkg.mk"
