# $NetBSD: Makefile,v 1.1.1.1 2005/02/11 16:40:43 minskim Exp $

DISTNAME=	pgpool-2.5
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/157/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pgfoundry.org/projects/pgpool/
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
