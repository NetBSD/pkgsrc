# $NetBSD: Makefile,v 1.6 2005/05/15 17:04:32 adrianp Exp $
#

DISTNAME=	bugzilla-2.18.1
CATEGORIES=	www devel
MASTER_SITES=	http://ftp.mozilla.org/pub/mozilla.org/webtools/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.bugzilla.org/
COMMENT=	Web based bug tracking system

DEPENDS+=	p5-AppConfig>=1.52:../../devel/p5-AppConfig
DEPENDS+=	p5-CGI>=2.93:../../www/p5-CGI
DEPENDS+=	p5-File-Spec>=0.82:../../devel/p5-File-Spec
DEPENDS+=	p5-File-Temp-[0-9]*:../../devel/p5-File-Temp
DEPENDS+=	p5-Template-Toolkit>=2.08:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Text-Tabs+Wrap>=2001.0131:../../textproc/p5-Text-Tabs+Wrap
DEPENDS+=	p5-TimeDate>=1.14:../../time/p5-TimeDate
DEPENDS+=	p5-DBD-mysql>=2.1010:../../databases/p5-DBD-mysql

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

NO_BUILD=	YES
USE_PKGINSTALL=	YES
PERL5_REQD+=	5.6.0

BUILDLINK_DEPENDS.p5-DBI+=		p5-DBI>=1.36
BUILDLINK_DEPENDS.mysql-client+=	mysql-client>=3.23.41

BZ_WEB_GROUP?=	www
SENDMAIL?=	/usr/sbin/sendmail

BUILD_DEFS+= 	BZ_WEB_GROUP SENDMAIL APACHE_USER

MESSAGE_SUBST+=	BZDIR=${BZDIR} PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

BZDIR=		${PREFIX}/share/bugzilla
EGDIR=		${PREFIX}/share/examples/bugzilla
DOCDIR=		${PREFIX}/share/doc/bugzilla
CONF_FILES=	${EGDIR}/bugzilla.conf ${PKG_SYSCONFDIR}/bugzilla.conf \
		${EGDIR}/localconfig ${BZDIR}/localconfig
SPECIAL_PERMS=	${BZDIR}/localconfig ${APACHE_USER} ${SHAREGRP} 0400

REPLACE_PERL=	*.pl *.cgi

SUBST_CLASSES=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	bugzilla.conf localconfig Bugzilla/BugMail.pm
SUBST_SED.conf=		-e "s|@BZ_WEB_GROUP@|${BZ_WEB_GROUP}|g"		\
			-e "s|@PREFIX@|${PREFIX}|g"			\
			-e "s|@BZDIR@|${BZDIR}|g"			\
			-e "s|/usr/lib/sendmail|${SENDMAIL}|g"
SUBST_MESSAGE.conf=	"Fixing configuration files."

post-extract:
	@${FIND} ${WRKSRC}/template -type d -name CVS | ${XARGS} ${RM} -rf
	@${FIND} ${WRKSRC}/template -type f -name ".cvsignore" | ${XARGS} \
		${RM} -f
	@${CP} ${FILESDIR}/bugzilla.conf ${WRKSRC}
	@${CP} ${FILESDIR}/localconfig ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${BZDIR}
	${INSTALL_DATA_DIR} ${BZDIR}/Bugzilla
	${INSTALL_DATA_DIR} ${BZDIR}/Bugzilla/Auth
	${INSTALL_DATA_DIR} ${BZDIR}/Bugzilla/Template/Plugin
	${INSTALL_DATA_DIR} ${BZDIR}/css
	${INSTALL_DATA_DIR} ${BZDIR}/js
	${INSTALL_DATA_DIR} ${BZDIR}/template
	${INSTALL_DATA_DIR} ${BZDIR}/skins
	${INSTALL_DATA_DIR} ${BZDIR}/skins/standard
	${INSTALL_DATA_DIR} ${BZDIR}/docs/html
	${INSTALL_DATA_DIR} ${BZDIR}/docs/images
	${INSTALL_DATA_DIR} ${BZDIR}/docs/images/callouts
	${INSTALL_DATA} ${WRKSRC}/docs/txt/Bugzilla-Guide.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/rel_notes.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/QUICKSTART ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/UPGRADING-pre-2.8 ${DOCDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.cgi ${BZDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/Bugzilla.pm ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/Bugzilla/*.pm ${BZDIR}/Bugzilla
	${INSTALL_DATA} ${WRKSRC}/Bugzilla/Auth/*.pm ${BZDIR}/Bugzilla/Auth
	${INSTALL_DATA} ${WRKSRC}/Bugzilla/Template/Plugin/*.pm \
		${BZDIR}/Bugzilla/Template/Plugin
	${INSTALL_DATA} ${WRKSRC}/robots.txt ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/1x1.gif ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/ant.jpg ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/padlock.png ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/localconfig ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/bugzilla.dtd ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/*.js ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/js/*.js ${BZDIR}/js
	${INSTALL_DATA} ${WRKSRC}/duplicates.xul ${BZDIR}
	${INSTALL_DATA} ${WRKSRC}/css/*.css ${BZDIR}/css
	${INSTALL_DATA} ${WRKSRC}/docs/html/*.html ${BZDIR}/docs/html
	cd ${WRKSRC}/template && ${PAX} -rw . ${BZDIR}/template
	${FIND} ${BZDIR}/template -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	${FIND} ${BZDIR}/template -type d | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${CHMOD} ${BINMODE} ${BZDIR}/template/en/default/filterexceptions.pl
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${BZDIR}/template
	${INSTALL_DATA} ${WRKSRC}/skins/standard/*.css ${BZDIR}/skins/standard
	${INSTALL_DATA} ${WRKSRC}/docs/images/*.gif ${BZDIR}/docs/images
	${INSTALL_DATA} ${WRKSRC}/docs/images/*.png ${BZDIR}/docs/images
	${INSTALL_DATA} ${WRKSRC}/docs/images/*.xml ${BZDIR}/docs/images
	${INSTALL_DATA} ${WRKSRC}/docs/images/callouts/*.gif \
		${BZDIR}/docs/images/callouts

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
