# $NetBSD: Makefile,v 1.45 2006/09/09 23:20:11 bouyer Exp $

DISTNAME=	mailman-2.1.9rc1
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mailman/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.list.org/
COMMENT=	The GNU Mailing List Manager

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${EXECDIR}

MAKE_FLAGS+=		DIRSETGID=${TRUE:Q}
EXECDIR=		${PREFIX}/lib/mailman
MAILMAN_DATADIR?=	${VARBASE}/db/mailman
EGDIR=                  ${PREFIX}/share/examples/mailman
DOCDIR=                 ${PREFIX}/share/doc/mailman
MAILMAN_USER?= 		mailman
MAILMAN_GROUP?= 	mailman
MAILMAN_CGIGROUP?= 	${APACHE_GROUP}
MAILMAN_MAILGROUP?= 	daemon	# group sendmail runs under;
                                # use 'nobody' for postfix
MAILMAN_CGIEXT?=	.cgi

MESSAGE_SUBST+=		EXECDIR=${EXECDIR}
MESSAGE_SUBST+=		MAILMAN_USER=${MAILMAN_USER}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PLIST_SUBST+=		MAILMAN_CGIEXT=${MAILMAN_CGIEXT:S/none//}

PKG_GROUPS=		${MAILMAN_GROUP}
PKG_USERS=		${MAILMAN_USER}:${MAILMAN_GROUP}

PKG_GECOS.${MAILMAN_USER}=	Mailman user
PKG_SHELL.${MAILMAN_USER}=	${SH}

REQD_DIRS_PERMS+=	${EXECDIR} root ${MAILMAN_GROUP} 775
OWN_DIRS_PERMS+=	${MAILMAN_DATADIR} ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/archives ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/archives/public ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/archives/private ${MAILMAN_USER} ${MAILMAN_GROUP} 771
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/data ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/lists ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/locks ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/logs ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/qfiles ${MAILMAN_USER} ${MAILMAN_GROUP} 775
MAKE_DIRS_PERMS+=	${MAILMAN_DATADIR}/spam ${MAILMAN_USER} ${MAILMAN_GROUP} 775

CONF_FILES+=		${EGDIR}/mailman.conf ${PKG_SYSCONFDIR}/mailman.conf
CONF_FILES+=		${EXECDIR}/Mailman/mm_cfg.py.dist ${EXECDIR}/Mailman/mm_cfg.py

RCD_SCRIPTS=		mailman

INSTALL_TEMPLATES+=	${FILESDIR}/INSTALL
DEINSTALL_TEMPLATES+=	${FILESDIR}/DEINSTALL

PYTHON_VERSIONS_ACCEPTED= 24 23 22 21
PYTHON_PATCH_SCRIPTS+=	Mailman/Archiver/pipermail.py
PYTHON_PATCH_SCRIPTS+=	Mailman/Post.py
PYTHON_PATCH_SCRIPTS+=	admin/bin/faq2ht.py
PYTHON_PATCH_SCRIPTS+=	admin/bin/mm2do
PYTHON_PATCH_SCRIPTS+=	admin/www/reset_pw.py
PYTHON_PATCH_SCRIPTS+=	bin/msgfmt.py

CONFIGURE_ARGS+=	--with-cgi-gid=${MAILMAN_CGIGROUP:Q}
.if ${MAILMAN_CGIEXT} != "none"
CONFIGURE_ARGS+=	--with-cgi-ext=${MAILMAN_CGIEXT:Q}
.endif
CONFIGURE_ARGS+=	--with-groupname=${MAILMAN_GROUP:Q}
CONFIGURE_ARGS+=	--with-mail-gid=${MAILMAN_MAILGROUP:Q}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN:Q}
CONFIGURE_ARGS+=	--with-username=${MAILMAN_USER:Q}
CONFIGURE_ARGS+=	--with-var-prefix=${MAILMAN_DATADIR:Q}
CONFIGURE_ARGS+=	--without-permcheck

# Put in externally invalid defaults (MESSAGE directs how to fix it)
CONFIGURE_ARGS+=	--with-mailhost=localhost
CONFIGURE_ARGS+=	--with-urlhost=localhost

BUILD_DEFS+=		MAILMAN_DATADIR
BUILD_DEFS+=		MAILMAN_USER
BUILD_DEFS+=		MAILMAN_GROUP
BUILD_DEFS+=		MAILMAN_CGIGROUP
BUILD_DEFS+=		MAILMAN_MAILGROUP
BUILD_DEFS+=		MAILMAN_CGIEXT

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailman.conf.dist
SUBST_SED.paths+=	-e 's,@EXECDIR@,${EXECDIR},g'
SUBST_SED.paths+=	-e 's,@MAILMAN_DATADIR@,${MAILMAN_DATADIR},g'
SUBST_STAGE.paths=	post-patch

PYCOMPILEALL=	${BUILDLINK_PREFIX.${PYPACKAGE}}/${PYLIB}/compileall.py

post-extract:
	${CP} ${FILESDIR}/mailman.conf.dist ${WRKDIR}/mailman.conf.dist

post-patch:
	${RM} -f ${WRKSRC}/[A-Z]*.orig

pre-install:
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m 775 ${EXECDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXECDIR}/support

post-install:
	cd ${WRKSRC} && for i in [A-IN-U]*; do \
		${INSTALL_DATA} $$i ${DOCDIR}/; \
	done
	cd ${WRKSRC}/admin/www && for i in \
	    mailman-*.ps mailman-*.pdf mailman-*.txt; do \
		${INSTALL_DATA} $$i ${DOCDIR}/; \
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mailman.conf.dist ${EGDIR}/mailman.conf
	${CHOWN} -R root:${MAILMAN_GROUP} ${EXECDIR}
	${CHMOD} -R g+w ${EXECDIR}
	${CHMOD} g+s ${EXECDIR}/cgi-bin/*
	${RM} -f ${EXECDIR}/Mailman/mm_cfg.pyc
	${PYTHONBIN} ${PYCOMPILEALL} ${PREFIX}/lib/mailman/bin ${PREFIX}/lib/mailman/cron ${PREFIX}/lib/mailman/scripts

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
