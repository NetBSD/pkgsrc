# $NetBSD: Makefile,v 1.1.1.1 2003/07/12 14:43:08 salo Exp $
#

DISTNAME=	pure-ftpd-1.0.15
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pureftpd/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.pureftpd.org/
COMMENT=	FTP daemon with optional SQL support

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-sysquotas	\
			--with-ftpwho		\
			--with-virtualvhosts	\
			--with-virtualchroot	\
			--with-diraliases	\
			--with-ratios		\
			--with-throttling	\
			--with-altlog		\
			--with-puredb		\
			--with-quotas

.include "../../mk/bsd.prefs.mk"

.if defined(PURE_FTPD_USE_MYSQL) && !empty(PURE_FTPD_USE_MYSQL:M[Yy][Ee][Ss])
.include "../../databases/mysql-client/buildlink2.mk"
CONFIGURE_ARGS+=	--with-mysql
BUILD_DEFS+=		PURE_FTPD_USE_MYSQL
.endif

.if defined(PURE_FTPD_USE_PGSQL) && !empty(PURE_FTPD_USE_PGSQL:M[Yy][Ee][Ss])
.include "../../databases/postgresql-lib/buildlink2.mk"
CONFIGURE_ARGS+=	--with-pgsql
CPPFLAGS+=		-I${BUILDLINK_DIR}/include/pgsql
BUILD_DEFS+=		PURE_FTPD_USE_PGSQL
.endif

RCD_SCRIPTS=	pure_ftpd

.include "../../mk/bsd.pkg.mk"
