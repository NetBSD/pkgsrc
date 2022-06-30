# $NetBSD: Makefile,v 1.24 2022/06/30 11:18:08 nia Exp $
#

CASSANDRA_VER=	3.11.2
PKGREVISION=	3

USE_JAVA2=	8

BINFILES=	cassandra cassandra.in.sh cqlsh cqlsh.py debug-cql nodetool	\
		sstableloader sstablescrub sstableupgrade sstableutil		\
		sstableverify stop-server
DOCFILES=	#
EGFILES=	cassandra-env.sh cassandra-jaas.config 				\
		cassandra-rackdc.properties cassandra-topology.properties	\
		cassandra.yaml commitlog_archiving.properties cqlshrc.sample	\
		hotspot_compiler jvm.options logback-tools.xml logback.xml 	\
		metrics-reporter-config-sample.yaml

.include "../../databases/apache-cassandra/Makefile.common"
.include "../../mk/bsd.pkg.mk"
