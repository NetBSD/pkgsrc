# $NetBSD: Makefile,v 1.6 2002/06/11 11:14:30 wiz Exp $
#

DISTNAME=	pure-ftpd-1.0.12
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pureftpd/}
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

post-build:
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/pure_ftpd > ${WRKDIR}/pure_ftpd

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/pure_ftpd ${PREFIX}/etc/rc.d/pure_ftpd

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
