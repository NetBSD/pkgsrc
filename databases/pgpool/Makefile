# $NetBSD: Makefile,v 1.2 2005/02/11 16:49:24 minskim Exp $

DISTNAME=	pgpool-2.5
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/157/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pgpool.projects.postgresql.org/
COMMENT=	Connection pooling/replication server for PostgreSQL

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_PKGINSTALL=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

CONF_FILES=	${PREFIX}/share/examples/pgpool.conf.sample		\
		${PKG_SYSCONFDIR}/pgpool.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/pgpool.conf.sample ${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
