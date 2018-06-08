# $NetBSD: Makefile,v 1.3 2018/06/08 09:34:01 fhajny Exp $
#

CASSANDRA_VER=	2.2.12

MASTER_SITES=	${MASTER_SITE_APACHE:=cassandra/${CASSANDRA_VER:C/-.*//}/}

DEPENDS+=	snappy-java10>=1.0.5:../../devel/snappy-java10

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
	${LN} -sf ${PREFIX}/lib/java/snappy-java/snappy-java-1.0.5.jar \
		${DESTDIR}${PREFIX}/share/cassandra/lib/snappy-java.jar

.include "../../mk/bsd.pkg.mk"
