# $NetBSD: Makefile,v 1.7 2006/07/21 23:28:37 abs Exp $
#

DISTNAME=	munin_${VER}
VER=		1.3.1
PKGNAME=	munin-node-${VER}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/}
PKGREVISION=	4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://munin.sourceforge.net/
COMMENT=	System monitoring tool, client version

DEPENDS+=	p5-Net-Server>=0:../../net/p5-Net-Server
DEPENDS+=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay
DEPENDS+=	munin-doc>=1.3.1:../../sysutils/munin-doc

USE_TOOLS+=	perl:run
USE_TOOLS+=	gmake
USE_PKGINSTALL=	YES

WRKSRC=		${WRKDIR}/${DISTNAME:S:_:-:}

MUNIN_GROUP?=	munin
MUNIN_USER?=	munin

PKG_GROUPS=	${MUNIN_GROUP}
PKG_USERS=	${MUNIN_USER}:${MUNIN_GROUP}::Munin\\ user
PKG_SYSCONFSUBDIR?=	munin
REPLACE_PERL+=	node/node.d/*.in

STATEDIR?=	${VARBASE}/munin/plugin-state
MUNIN_RUN?=	${VARBASE}/run/munin

MAKE_DIRS=	${VARBASE}/munin
MAKE_DIRS+=	${VARBASE}/run/munin
MAKE_DIRS+=	${VARBASE}/log/munin
MAKE_DIRS+=	${STATEDIR}

OWN_DIRS=	${VARBASE}/munin
OWN_DIRS+=	${VARBASE}/run/munin
OWN_DIRS+=	${VARBASE}/log/munin
OWN_DIRS+=	${VARBASE}/munin/plugin-state

OWN_DIRS_PERMS+=${VARBASE}/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${VARBASE}/run/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${VARBASE}/log/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=${VARBASE}/munin/plugin-state ${MUNIN_USER} ${MUNIN_GROUP} 0775

INSTALL_TARGET=	install-node install-node-plugins

BUILD_TARGET=	build

#MAKE_ENV+=	PERL5_SITELIB=${PERL5_SITELIB}
MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	MUNIN_USER=${MUNIN_USER}
MAKE_ENV+=	MUNIN_GROUP=${MUNIN_GROUP}
MAKE_ENV+=	PERL5=${PERL5:Q}

FILES_SUBST+=	PERL=${PERL5:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=	STATEDIR=${STATEDIR}
FILES_SUBST+=	MUNIN_RUN=${MUNIN_RUN:Q}
FILES_SUBST+=	MUNIN_USER=${MUNIN_USER:Q}
FILES_SUBST+=	MUNIN_GROUP=${MUNIN_GROUP:Q}

MESSAGE_SUBST+=	VARBASE=${VARBASE:Q}

RCD_SCRIPTS+=	munin-node

EGDIR=		${PREFIX}/share/examples/munin

CONF_FILES+=	${EGDIR}/munin-node.conf ${PKG_SYSCONFDIR}/munin-node.conf


pre-configure:
	cd ${FILESDIR}; ${TAR} cf - . | (cd ${WRKSRC}; ${TAR} xfp -)

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/build/node/munin-node.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
.include "../../lang/python/application.mk"
