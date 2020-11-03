# $NetBSD: Makefile,v 1.1 2020/11/03 22:52:41 otis Exp $

.include "../../sysutils/zabbix50-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-java-/}
COMMENT=	Enterprise-class Monitoring Solution for Everyone

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-java
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONFIGURE_ENV+=	JAVAC=${PKG_JAVA_HOME}/bin/javac
CONFIGURE_ENV+=	JAR=${PKG_JAVA_HOME}/bin/jar

USE_JAVA=	run
PKG_JVMS_ACCEPTED=	openjdk8

EGDIR=		share/examples/zabbix

INSTALLATION_DIRS+=	${EGDIR} share/zabbix

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		conf/*.conf
SUBST_FILES.fix-paths+=		man/*.man
SUBST_SED.fix-paths=		-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
