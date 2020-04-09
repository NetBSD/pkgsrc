# $NetBSD: Makefile,v 1.42 2020/04/09 15:00:47 tm Exp $
#

PKGNAME=	${DISTNAME:S/munin/munin-node/}
COMMENT=	System monitoring tool, client version

.include "../../sysutils/munin-common/Makefile.common"

DEPENDS+=	munin-common>=${PKGVERSION_NOREV}:../../sysutils/munin-common
DEPENDS+=	p5-IO-Socket-INET6>=0:../../net/p5-IO-Socket-INET6
DEPENDS+=	p5-List-MoreUtils>=0:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Net-Server>=0:../../net/p5-Net-Server
DEPENDS+=	p5-Socket6>=0:../../net/p5-Socket6
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes

OWN_DIRS=		${PKG_SYSCONFDIR}/plugin-conf.d
OWN_DIRS+=		${PKG_SYSCONFDIR}/plugins

OWN_DIRS_PERMS+=	${MUNIN_DBDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_LOGDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_PLUGSTATE} nobody ${MUNIN_GROUP} 0775
OWN_DIRS_PERMS+=	${MUNIN_SPOOLDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0775
OWN_DIRS_PERMS+=	${MUNIN_STATEDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755

REPLACE_PERL+=		node/sbin/munin-node
REPLACE_PERL+=		node/sbin/munin-node-configure
REPLACE_PERL+=		node/sbin/munin-run
REPLACE_PERL+=		plugins/node.d/slony_lag_.in

CONF_FILES+=		${EGDIR}/munin-node.conf ${PKG_SYSCONFDIR}/munin-node.conf
INSTALLATION_DIRS+=	${EGDIR}

CHECK_INTERPRETER_SKIP+=	lib/munin/plugins/tomcat_

CHECK_PORTABILITY_SKIP+=	plugins/*

RCD_SCRIPTS+=		munin-node

BUILD_TARGET=		build
INSTALL_TARGET=		install-node install-node-plugins

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/node/munin-node.conf ${DESTDIR}${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
