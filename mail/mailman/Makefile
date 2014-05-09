# $NetBSD: Makefile,v 1.70 2014/05/09 07:37:10 wiz Exp $

DISTNAME=	mailman-2.1.14-1
PKGNAME=	mailman-2.1.14.1
PKGREVISION=	4
CATEGORIES=	mail www
MASTER_SITES=	http://launchpad.net/mailman/2.1/2.1.14/+download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.list.org/
COMMENT=	The GNU Mailing List Manager
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	destdir

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${EXECDIR}

MAKE_FLAGS+=		DIRSETGID=${TRUE:Q}
EXECDIR=		${PREFIX}/lib/mailman
MAILMAN_DATADIR?=	${VARBASE}/db/mailman
EGDIR=			${PREFIX}/share/examples/mailman
DOCDIR=			${PREFIX}/share/doc/mailman
MAILMAN_USER?=		mailman
MAILMAN_GROUP?=		mailman
MAILMAN_CGIGROUP?=	${APACHE_GROUP}
MAILMAN_MAILGROUP?=	daemon	# group sendmail runs under;
                                # use 'nobody' for postfix
MAILMAN_CGIEXT?=	.cgi

MESSAGE_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		MAILMAN_USER=${MAILMAN_USER}
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}
PLIST_SUBST+=		MAILMAN_CGIEXT=${MAILMAN_CGIEXT:S/none//}

PKG_GROUPS_VARS+=	MAILMAN_GROUP MAILMAN_CGIGROUP MAILMAN_MAILGROUP
PKG_USERS_VARS+=	MAILMAN_USER

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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 2.1.14.1
REPLACE_PYTHON+=	Mailman/Archiver/pipermail.py
REPLACE_PYTHON+=	Mailman/Post.py
REPLACE_PYTHON+=	bin/msgfmt.py

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

# dont create egg-info files in pythonlib
INSTALL_ENV+=		PKGSRC_PYTHON_NO_EGG=defined

BUILD_DEFS+=		MAILMAN_DATADIR
BUILD_DEFS+=		MAILMAN_CGIEXT

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/mailman.conf.dist
SUBST_SED.paths+=	-e 's,@EXECDIR@,${EXECDIR},g'
SUBST_SED.paths+=	-e 's,@MAILMAN_DATADIR@,${MAILMAN_DATADIR},g'
SUBST_STAGE.paths=	post-patch

# mailman depends a lot on it and will bitch if changed.
CHECK_PERMS=	no

REPLACE_PYTHON+=	cron/senddigests tests/fblast.py tests/onebounce.py

post-extract:
	${CP} ${FILESDIR}/mailman.conf.dist ${WRKDIR}/mailman.conf.dist

post-patch:
	${RM} -f ${WRKSRC}/[A-Z]*.orig

pre-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${EXECDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${EXECDIR}/support

post-install:
	cd ${WRKSRC} && for i in [A-IN-U]*; do \
		${INSTALL_DATA} $$i ${DESTDIR}${DOCDIR}/; \
	done
	cd ${WRKSRC}/doc && for i in \
	    mailman-*.ps mailman-*.pdf mailman-*.txt; do \
		${INSTALL_DATA} $$i ${DESTDIR}${DOCDIR}/; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mailman.conf.dist ${DESTDIR}${EGDIR}/mailman.conf
	${INSTALL_DATA} ${WRKSRC}/cron/crontab.in ${DESTDIR}${EGDIR}/crontab.in
	${CHMOD} -R g+w ${DESTDIR}${EXECDIR}
	${CHMOD} g+s ${DESTDIR}${EXECDIR}/cgi-bin/*
	${PY_COMPILE_ALL} ${DESTDIR}${PREFIX}/lib/mailman/bin ${DESTDIR}${PREFIX}/lib/mailman/cron ${DESTDIR}${PREFIX}/lib/mailman/scripts

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
