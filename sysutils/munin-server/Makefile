# $NetBSD: Makefile,v 1.25 2018/08/22 09:46:36 wiz Exp $
#

DISTNAME=	${PKGNAME_NOREV:S:-server-:_:}
PKGNAME=	munin-server-1.3.2
PKGREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://munin-monitoring.org/
COMMENT=	System monitoring tool, server version

PKG_DESTDIR_SUPPORT=	destdir

DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-HTML-Template>=0:../../www/p5-HTML-Template
DEPENDS+=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay
DEPENDS+=	rrdtool>=1.2:../../databases/rrdtool
DEPENDS+=	munin-doc>=1.3.1:../../sysutils/munin-doc

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
DEPENDS+=	modular-xorg-fonts>0:../../meta-pkgs/modular-xorg-fonts
.endif

USE_TOOLS+=	gmake perl:run
USE_PKGINSTALL=	YES

PERL5_CONFIGURE=NO

WRKSRC=		${WRKDIR}/${DISTNAME:S:_:-:}
CHECK_PORTABILITY_SKIP+=	node/node.d/*

PKG_GROUPS_VARS+=	MUNIN_GROUP
PKG_USERS_VARS+=	MUNIN_USER

MUNIN_GROUP?=	munin
MUNIN_USER?=	munin

PKG_GROUPS=	${MUNIN_GROUP}
PKG_USERS=	${MUNIN_USER}:${MUNIN_GROUP}
PKG_GECOS.${MUNIN_USER}=	Munin user
PKG_HOME.${MUNIN_USER}=		${VARBASE}/munin
USERGROUP_PHASE=	pre-install

PKG_SYSCONFSUBDIR?=	munin

STATEDIR=	${VARBASE}/munin/plugin-state

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

BUILD_DEFS+=	VARBASE

INSTALL_TARGET=	install-main

BUILD_TARGET=	build

PERL5_SITELIB=	${PERL5_SUB_INSTALLVENDORLIB:Q}

MAKE_ENV+=	PERL5_SITELIB=${PREFIX}/${PERL5_SITELIB}
MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}
INSTALL_MAKE_ENV+=	CONFDIR=${DESTDIR}${PKG_SYSCONFDIR}
MAKE_ENV+=	MUNIN_USER=${MUNIN_USER}
MAKE_ENV+=	MUNIN_GROUP=${MUNIN_GROUP}
MAKE_ENV+=	PERL5=${PERL5:Q}

FILES_SUBST+=	PERL=${PERL5:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=	STATEDIR=${STATEDIR}

PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SITELIB:Q}

MESSAGE_SUBST+=	MUNIN_USER=${MUNIN_USER}
MESSAGE_SUBST+=	VARBASE=${VARBASE}

EGDIR=		${PREFIX}/share/examples/munin
TMPL_EGDIR=	${EGDIR}/templates
INST_TMPL_DIR=	${PKG_SYSCONFDIR}/templates

CONF_FILES+=	${EGDIR}/munin.conf ${PKG_SYSCONFDIR}/munin.conf

TMPL_FILES=	definitions.html logo.png munin-comparison-day.tmpl \
		munin-comparison-month.tmpl munin-comparison-week.tmpl \
		munin-comparison-year.tmpl munin-domainview.tmpl \
		munin-nodeview.tmpl munin-overview.tmpl \
		munin-serviceview.tmpl style.css

.for f in ${TMPL_FILES}
CONF_FILES+=	${TMPL_EGDIR}/${f} ${INST_TMPL_DIR}/${f}
.endfor

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/build/server/munin.conf ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
.include "../../lang/perl5/module.mk"
