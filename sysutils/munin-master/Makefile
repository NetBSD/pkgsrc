# $NetBSD: Makefile,v 1.2 2020/04/09 15:00:47 tm Exp $
#

PKGNAME=	${DISTNAME:S/munin/munin-master/}
COMMENT=	System monitoring tool, master version

.include "../../sysutils/munin-common/Makefile.common"

DEPENDS+=	munin-common>=${PKGVERSION_NOREV}:../../sysutils/munin-common
DEPENDS+=	p5-CGI-Fast>=0:../../www/p5-CGI-Fast
DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-File-Copy-Recursive>=0.38:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-HTML-Template>=0:../../www/p5-HTML-Template
DEPENDS+=	p5-IO-Socket-INET6>=2.69:../../net/p5-IO-Socket-INET6
DEPENDS+=	p5-Log-Log4perl>=1.18:../../devel/p5-Log-Log4perl
DEPENDS+=	p5-Net-SSLeay>=0:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes
DEPENDS+=	p5-URI>=1.60:../../www/p5-URI
DEPENDS+=	rrdtool>=1.2:../../databases/rrdtool

OWN_DIRS+=		${PKG_SYSCONFDIR}/munin-conf.d
OWN_DIRS+=		${PKG_SYSCONFDIR}/static
OWN_DIRS+=		${PKG_SYSCONFDIR}/templates
OWN_DIRS+=		${PKG_SYSCONFDIR}/templates/partial

OWN_DIRS_PERMS+=	${MUNIN_DBDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_DBDIR}/cgi-tmp nobody ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_LOGDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_SPOOLDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0775
OWN_DIRS_PERMS+=	${MUNIN_STATEDIR} ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_WWWDIR}/munin ${MUNIN_USER} ${MUNIN_GROUP} 0755
OWN_DIRS_PERMS+=	${MUNIN_WWWDIR}/munin/data ${MUNIN_USER} ${MUNIN_GROUP} 0755

TMPL_EGDIR=	${EGDIR}/templates
STATIC_EGDIR=	${EGDIR}/static
INST_TMPL_DIR=	${PKG_SYSCONFDIR}/templates

TMPL_FILES=	munin-categoryview.tmpl munin-comparison-day.tmpl \
		munin-comparison-month.tmpl munin-comparison-week.tmpl \
		munin-comparison-year.tmpl munin-domainview.tmpl \
		munin-dynazoom.tmpl munin-nodeview.tmpl munin-overview.tmpl \
		munin-problemview.tmpl munin-serviceview.tmpl \
		partial/bottom_navigation.tmpl partial/footer.tmpl \
		partial/generated_by.tmpl partial/head.tmpl partial/logo_navigation.tmpl \
		partial/logo_navigation_comparison.tmpl \
		partial/logo_navigation_problem.tmpl partial/logo_path.tmpl \
		partial/navigation.tmpl partial/path.tmpl

STATIC_FILES=	definitions.html dynazoom.html favicon.ico formatdate.js \
		logo-h.png logo.png querystring.js zoom.js \
		style-1.2.css style-new.css style.css

CONF_FILES+=	${EGDIR}/munin.conf ${PKG_SYSCONFDIR}/munin.conf
.for f in ${TMPL_FILES}
CONF_FILES+=	${TMPL_EGDIR}/${f} ${INST_TMPL_DIR}/${f}
.endfor
.for f in ${STATIC_FILES}
CONF_FILES+=	${STATIC_EGDIR}/${f} ${PKG_SYSCONFDIR}/static/${f}
.endfor

INSTALLATION_DIRS+=	${EGDIR}

CHECK_PORTABILITY_SKIP+=	node/node.d/*
CHECK_PORTABILITY_SKIP+=	plugins/*

BUILD_TARGET=		build
INSTALL_TARGET=		install-master-prime

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
