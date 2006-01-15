# $NetBSD: Makefile,v 1.7 2006/01/15 17:09:50 minskim Exp $

DISTNAME=	pgpool-2.7
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/572/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pgpool.projects.postgresql.org/
COMMENT=	Connection pooling/replication server for PostgreSQL

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

CONF_FILES=	${PREFIX}/share/examples/pgpool.conf.sample		\
		${PKG_SYSCONFDIR}/pgpool.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/pgpool.conf.sample ${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
