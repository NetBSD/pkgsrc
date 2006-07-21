# $NetBSD: Makefile,v 1.5 2006/07/21 23:21:20 abs Exp $
#

DISTNAME=	${PKGNAME_NOREV:S:-server-:_:}
PKGNAME=	munin-server-1.3.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=munin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://munin.sourceforge.net/
COMMENT=	System monitoring tool, server version

DEPENDS+=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay
DEPENDS+=	rrdtool>=1.2:../../databases/rrdtool
DEPENDS+=	munin-doc>=1.3.1:../../sysutils/munin-doc

USE_TOOLS+=	gmake perl:run
USE_PKGINSTALL=	YES

PERL5_CONFIGURE=NO

WRKSRC=		${WRKDIR}/${DISTNAME:S:_:-:}

MUNIN_GROUP?=	munin
MUNIN_USER?=	munin

PKG_GROUPS=	${MUNIN_GROUP}
PKG_USERS=	${MUNIN_USER}:${MUNIN_GROUP}::Munin\\ user
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

INSTALL_TARGET=	install-main

BUILD_TARGET=	build

PERL5_SITELIB=	${PERL5_SUB_INSTALLVENDORLIB:Q}

MAKE_ENV+=	PERL5_SITELIB=${PREFIX}/${PERL5_SITELIB}
MAKE_ENV+=	CONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	MUNIN_USER=${MUNIN_USER}
MAKE_ENV+=	MUNIN_GROUP=${MUNIN_GROUP}
MAKE_ENV+=	PERL5=${PERL5:Q}

FILES_SUBST+=	PERL=${PERL5:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
FILES_SUBST+=	STATEDIR=${STATEDIR}

PLIST_SUBST+=	PERL5_SITELIB=${PERL5_SITELIB:Q}

MESSAGE_SUBST+=	MUNIN_USER=${MUNIN_USER:Q}
MESSAGE_SUBST+=	VARBASE=${VARBASE:Q}

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

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/build/server/munin.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
.include "../../lang/perl5/module.mk"
