# $NetBSD: Makefile,v 1.4 2002/05/07 23:12:05 hubertf Exp $
#

DISTNAME=	pure-ftpd-1.0.11
CATEGORIES=	net
MASTER_SITES=	http://belnet.dl.sourceforge.net/sourceforge/pureftpd/ \
		${MASTER_SITE_SOURCEFORGE:=pureftpd/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://www.pureftpd.org/
COMMENT=	FTP daemon with optional SQL support

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-sysquotas	\
			--with-ftpwho

.if defined(PURE_FTPD_USE_MYSQL) && ${PURE_FTPD_USE_MYSQL} == "YES"
DEPENDS+=	mysql-client>=3.23:../../databases/mysql-client
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}	\
		--with-quotas
CCPFLAGS+=	-I${LOCALBASE}/include/mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql -Wl,-R${LOCALBASE}/lib/mysql
BUILD_DEFS+=	PURE_FTPD_USE_MYSQL
.endif

.include "../../mk/bsd.pkg.mk"
