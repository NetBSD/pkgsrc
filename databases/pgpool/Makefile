# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:18 joerg Exp $

DISTNAME=	pgpool-2.7
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/572/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://pgpool.projects.postgresql.org/
COMMENT=	Connection pooling/replication server for PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	share/examples

CONF_FILES=	${PREFIX}/share/examples/pgpool.conf.sample		\
		${PKG_SYSCONFDIR}/pgpool.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/pgpool.conf.sample ${DESTDIR}${PREFIX}/share/examples

.include "../../mk/bsd.pkg.mk"
