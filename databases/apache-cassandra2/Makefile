# $NetBSD: Makefile,v 1.5 2019/04/25 07:32:40 maya Exp $
#

CASSANDRA_VER=	2.2.12
PKGREVISION=	2

MASTER_SITES=	${MASTER_SITE_APACHE:=cassandra/${CASSANDRA_VER:C/-.*//}/}

DEPENDS+=	snappy-java>=1.0.5.4<1.1:../../devel/snappy-java10

USE_JAVA2=	6

BINFILES=	cassandra cassandra.in.sh cqlsh cqlsh.py debug-cql		\
		nodetool sstablekeys sstableloader sstablescrub sstableupgrade	\
		sstableverify stop-server
DOCFILES=	CHANGES LICENSE NEWS NOTICE
EGFILES=	cassandra-env.sh cassandra-rackdc.properties			\
		cassandra-topology.properties cassandra.yaml			\
		commitlog_archiving.properties cqlshrc.sample			\
		hotspot_compiler logback-tools.xml logback.xml			\
		metrics-reporter-config-sample.yaml

.include "../../databases/apache-cassandra/Makefile.common"

post-extract:
	${RM} -f ${WRKSRC}/lib/snappy-java-*.jar

post-install:
	${LN} -sf ${PREFIX}/lib/java/snappy-java/snappy-java.jar \
		${DESTDIR}${PREFIX}/share/cassandra/lib/snappy-java.jar

.include "../../mk/bsd.pkg.mk"
