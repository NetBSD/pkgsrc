# $NetBSD: Makefile,v 1.2 2017/01/09 22:13:19 fhajny Exp $
#

CASSANDRA_VER=	2.1.16

MASTER_SITES=	${MASTER_SITE_APACHE:=cassandra/${CASSANDRA_VER:C/-.*//}/}

DEPENDS+=	snappy-java10>=1.0.5:../../devel/snappy-java10

BINFILES=	cassandra cassandra-cli cassandra.in.sh cqlsh debug-cql		\
		nodetool sstablekeys sstableloader sstablescrub sstableupgrade	\
		stop-server
DOCFILES=	CHANGES LICENSE NEWS NOTICE
EGFILES=	cassandra-env.sh cassandra-rackdc.properties			\
		cassandra-topology.properties cassandra.yaml			\
		commitlog_archiving.properties cqlshrc.sample			\
		logback-tools.xml logback.xml cassandra-topology.yaml		\
		metrics-reporter-config-sample.yaml

.include "../../databases/apache-cassandra/Makefile.common"

post-extract:
	${RM} -f ${WRKSRC}/lib/snappy-java-*.jar

post-install:
	${LN} -sf ${PREFIX}/lib/java/snappy-java/snappy-java-1.0.5.jar \
		${DESTDIR}${PREFIX}/share/cassandra/lib/snappy-java.jar

.include "../../mk/bsd.pkg.mk"
