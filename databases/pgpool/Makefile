# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:13 tv Exp $

DISTNAME=	pgpool-2.5
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/157/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pgpool.projects.postgresql.org/
COMMENT=	Connection pooling/replication server for PostgreSQL

GNU_CONFIGURE=	yes
USE_PKGINSTALL=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES=	${PREFIX}/share/examples/pgpool.conf.sample		\
		${PKG_SYSCONFDIR}/pgpool.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/pgpool.conf.sample ${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
