# $NetBSD: Makefile,v 1.3 2002/09/21 23:46:53 jlam Exp $

DISTNAME=	mailman-2.0.12
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_GNU:=mailman/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.list.org/
COMMENT=	the GNU Mailing List Manager

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

EXECDIR=		${PREFIX}/lib/mailman
MAILMAN_DATADIR?=	/var/db/mailman
EGDIR=                  ${PREFIX}/share/examples/mailman
DOCDIR=                 ${PREFIX}/share/doc/mailman
MAILMAN_USER?= 		mailman
MAILMAN_GROUP?= 	mailman
MAILMAN_MAILGROUP?= 	guest # group of user 'daemon'

MESSAGE_SUBST+=		EXECDIR=${EXECDIR}
FILES_SUBST+=		EXECDIR=${EXECDIR}
FILES_SUBST+=		MAILMAN_USER=${MAILMAN_USER}
FILES_SUBST+=		MAILMAN_GROUP=${MAILMAN_GROUP}
FILES_SUBST+=		MAILMAN_DATADIR=${MAILMAN_DATADIR}

PKG_GROUPS=	${MAILMAN_GROUP}
PKG_USERS=	${MAILMAN_USER}:${MAILMAN_GROUP}::Mailman\\ user::${SH}

# We have some extra steps to do at postinstall time
INSTALL_EXTRA_TMPL= files/install.local

OWN_DIRS=	${EXECDIR}
OWN_DIRS_PERMS= ${EXECDIR} root ${MAILMAN_GROUP} 755

OWN_DIRS=	${MAILMAN_DATADIR}
OWN_DIRS_PERMS= ${MAILMAN_DATADIR} ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS=	${MAILMAN_DATADIR}/logs
MAKE_DIRS_PERMS= ${MAILMAN_DATADIR}/logs ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/archives
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/archives ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/lists
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/lists ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/locks
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/locks ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/qfiles
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/qfiles ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/data
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/data ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/spam
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/spam ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/filters
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/filters ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/archives/public
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/archives/public ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS+=	${MAILMAN_DATADIR}/archives/private
MAKE_DIRS_PERMS+= ${MAILMAN_DATADIR}/archives/private ${MAILMAN_USER} ${MAILMAN_GROUP} 775

CONF_FILES+=    ${EGDIR}/mailman.conf ${PKG_SYSCONFDIR}/mailman.conf
CONF_FILES+=    ${EXECDIR}/Mailman/mm_cfg.py.dist ${EXECDIR}/Mailman/mm_cfg.py

NO_BIN_ON_FTP=          requires compiled-in hardcoded uid/gid
NO_BIN_ON_CDROM=        ${NO_BIN_ON_FTP}

PYTHON_VERSIONS_ACCEPTED=   21 20
PYTHON_PATCH_SCRIPTS= Mailman/Archiver/pipermail.py
PYTHON_PATCH_SCRIPTS+= Mailman/pythonlib/cgi.py
PYTHON_PATCH_SCRIPTS+= Mailman/pythonlib/smtplib.py
PYTHON_PATCH_SCRIPTS+= admin/bin/Release.py
PYTHON_PATCH_SCRIPTS+= admin/bin/faq2ht.py
PYTHON_PATCH_SCRIPTS+= admin/bin/mm2do
PYTHON_PATCH_SCRIPTS+= bin/add_members
PYTHON_PATCH_SCRIPTS+= bin/arch
PYTHON_PATCH_SCRIPTS+= bin/check_db
PYTHON_PATCH_SCRIPTS+= bin/check_perms
PYTHON_PATCH_SCRIPTS+= bin/clone_member
PYTHON_PATCH_SCRIPTS+= bin/config_list
PYTHON_PATCH_SCRIPTS+= bin/digest_arch
PYTHON_PATCH_SCRIPTS+= bin/dumpdb
PYTHON_PATCH_SCRIPTS+= bin/find_member
PYTHON_PATCH_SCRIPTS+= bin/list_lists
PYTHON_PATCH_SCRIPTS+= bin/list_members
PYTHON_PATCH_SCRIPTS+= bin/mmsitepass
PYTHON_PATCH_SCRIPTS+= bin/move_list
PYTHON_PATCH_SCRIPTS+= bin/newlist
PYTHON_PATCH_SCRIPTS+= bin/remove_members
PYTHON_PATCH_SCRIPTS+= bin/rmlist
PYTHON_PATCH_SCRIPTS+= bin/sync_members
PYTHON_PATCH_SCRIPTS+= bin/update
PYTHON_PATCH_SCRIPTS+= bin/version
PYTHON_PATCH_SCRIPTS+= bin/withlist
PYTHON_PATCH_SCRIPTS+= contrib/qmail-to-mailman.py
PYTHON_PATCH_SCRIPTS+= contrib/rotatelogs.py
PYTHON_PATCH_SCRIPTS+= contrib/securelinux_fix.py
PYTHON_PATCH_SCRIPTS+= cron/bumpdigests
PYTHON_PATCH_SCRIPTS+= cron/checkdbs
PYTHON_PATCH_SCRIPTS+= cron/gate_news
PYTHON_PATCH_SCRIPTS+= cron/mailpasswds
PYTHON_PATCH_SCRIPTS+= cron/nightly_gzip
PYTHON_PATCH_SCRIPTS+= cron/qrunner
PYTHON_PATCH_SCRIPTS+= cron/senddigests
PYTHON_PATCH_SCRIPTS+= filters/bowa-strip
PYTHON_PATCH_SCRIPTS+= misc/Cookie.py
PYTHON_PATCH_SCRIPTS+= scripts/answer_majordomo_mail
PYTHON_PATCH_SCRIPTS+= scripts/mailcmd
PYTHON_PATCH_SCRIPTS+= scripts/mailowner
PYTHON_PATCH_SCRIPTS+= scripts/owner
PYTHON_PATCH_SCRIPTS+= scripts/post
PYTHON_PATCH_SCRIPTS+= scripts/request

MAILMAN_CONFIGURE_ARGS= --with-python=${PYTHONBIN}
MAILMAN_CONFIGURE_ARGS+= -prefix=${EXECDIR}
MAILMAN_CONFIGURE_ARGS+= --with-var-prefix=${MAILMAN_DATADIR}
MAILMAN_CONFIGURE_ARGS+= --with-username=${MAILMAN_USER}
MAILMAN_CONFIGURE_ARGS+= --with-groupname=${MAILMAN_GROUP}
MAILMAN_CONFIGURE_ARGS+= --with-mail-gid=${MAILMAN_MAILGROUP}

# we can't do the configure things before install, because the user/group has
# to exist and this is only done after build
do-build: #nothing

pre-install:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailman.conf.dist \
	    >  ${WRKDIR}/mailman.conf.dist

do-install:
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m775 ${EXECDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; \
	./configure ${MAILMAN_CONFIGURE_ARGS}; \
	${MAKE} install
	cd ${WRKSRC}; \
	for i in ACKNOWLEDGMENTS BUGS FAQ INSTALL NEWS README README.BSD \
		README.EXIM README.LINUX README.NETSCAPE README.QMAIL \
		README.SENDMAIL TODO UPGRADING; do \
		${INSTALL_DATA} $$i ${DOCDIR}/; \
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKDIR}; ${INSTALL_DATA} mailman.conf.dist ${EGDIR}/mailman.conf
	${CHOWN} -R root ${EXECDIR}
	${CHMOD} -R g-w ${EXECDIR}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
