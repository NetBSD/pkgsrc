# $NetBSD: Makefile,v 1.3 2023/04/19 17:17:08 otis Exp $

.include "../../sysutils/zabbix60-server/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-java-/}
COMMENT=	Enterprise-class Monitoring Solution for Everyone

PATCHDIR=	${.CURDIR}/../../sysutils/zabbix60-server/patches
DISTINFO_FILE=	${.CURDIR}/../../sysutils/zabbix60-server/distinfo

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-java
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

CONFIGURE_ENV+=	JAVAC=${PKG_JAVA_HOME}/bin/javac
CONFIGURE_ENV+=	JAR=${PKG_JAVA_HOME}/bin/jar

USE_JAVA=	run
PKG_JVMS_ACCEPTED=	openjdk8 openjdk11

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		conf/*.conf
SUBST_FILES.fix-paths+=		man/*.man
SUBST_SED.fix-paths=		-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
