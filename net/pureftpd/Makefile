# $NetBSD: Makefile,v 1.9 2003/03/07 18:21:48 salo Exp $
#

DISTNAME=	pure-ftpd-1.0.14
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pureftpd/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.pureftpd.org/
COMMENT=	FTP daemon with optional SQL support

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
			--with-puredb

.if defined(PURE_FTPD_USE_MYSQL) && ${PURE_FTPD_USE_MYSQL} == "YES"
DEPENDS+=	mysql-client>=3.23:../../databases/mysql-client
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}	\
		--with-quotas
CCPFLAGS+=	-I${LOCALBASE}/include/mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql -Wl,-R${LOCALBASE}/lib/mysql
BUILD_DEFS+=	PURE_FTPD_USE_MYSQL
.endif

RCD_SCRIPTS=	pure_ftpd

.include "../../mk/bsd.pkg.mk"
