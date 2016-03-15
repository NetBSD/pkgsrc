# $NetBSD: Makefile,v 1.20 2016/03/15 10:55:25 fhajny Exp $
#

CASSANDRA_VER=	1.2.19
PKGREVISION=	1

MASTER_SITES=	http://archive.apache.org/dist/cassandra/${PKGVERSION_NOREV}/

BINFILES=	cassandra cassandra-cli cassandra.in.sh cqlsh debug-cql		\
		json2sstable nodetool sstable2json sstablekeys sstableloader	\
		sstablescrub sstablesplit sstableupgrade stop-server
DOCFILES=	CHANGES LICENSE NEWS NOTICE README
EGFILES=	cassandra-env.sh cassandra-rackdc.properties			\
		cassandra-topology.properties cassandra.yaml			\
		commitlog_archiving.properties cqlshrc.sample			\
		log4j-server.properties	log4j-tools.properties

.include "../../databases/apache-cassandra/Makefile.common"
.include "../../mk/bsd.pkg.mk"
