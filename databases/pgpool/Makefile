# $NetBSD: Makefile,v 1.11 2012/10/02 21:25:38 asau Exp $

DISTNAME=	pgpool-3.4.1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1446/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pgpool.projects.postgresql.org/
COMMENT=	Connection pooling/replication server for PostgreSQL

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	share/examples

CONF_FILES=	${PREFIX}/share/examples/pgpool.conf.sample	\
		${PKG_SYSCONFDIR}/pgpool.conf
CONF_FILES+=	${PREFIX}/share/examples/pool_hba.conf.sample	\
		${PKG_SYSCONFDIR}/pool_hba.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/pgpool.conf.sample \
		${DESTDIR}${PREFIX}/share/examples
	${INSTALL_DATA} ${WRKSRC}/pool_hba.conf.sample \
		${DESTDIR}${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
