# $NetBSD: Makefile,v 1.8 2003/12/23 11:02:13 xtraeme Exp $

DISTNAME=	mailman-2.1.3
CATEGORIES=	mail www
MASTER_SITES=	http://www.list.org/ \
		${MASTER_SITE_GNU:=mailman/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.list.org/
COMMENT=	The GNU Mailing List Manager

.include "../../mk/bsd.prefs.mk"

USE_PKGINSTALL=		yes
PKG_SYSCONFSUBDIR?=	httpd
MESSAGE_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${EXECDIR}

MAKE_FLAGS+=		DIRSETGID=${TRUE}

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
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

PKG_GROUPS=		${MAILMAN_GROUP}
PKG_USERS=		${MAILMAN_USER}:${MAILMAN_GROUP}::Mailman\\ user::${SH}

OWN_DIRS_PERMS+=	${EXECDIR} root ${MAILMAN_GROUP} 755
OWN_DIRS_PERMS+=	${MAILMAN_DATADIR} ${MAILMAN_USER} ${MAILMAN_GROUP} 755
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

PYTHON_VERSIONS_ACCEPTED= 22 21
PYTHON_PATCH_SCRIPTS+=	Mailman/Archiver/pipermail.py
PYTHON_PATCH_SCRIPTS+=	Mailman/Post.py
PYTHON_PATCH_SCRIPTS+=	admin/bin/Release.py
PYTHON_PATCH_SCRIPTS+=	admin/bin/faq2ht.py
PYTHON_PATCH_SCRIPTS+=	admin/bin/mm2do
PYTHON_PATCH_SCRIPTS+=	bin/msgfmt.py

APACHE_GROUP?=		www

CONFIGURE_ARGS+=	--with-cgi-gid=${APACHE_GROUP}
CONFIGURE_ARGS+=	--with-cgi-ext=.cgi
CONFIGURE_ARGS+=	--with-groupname=${MAILMAN_GROUP}
CONFIGURE_ARGS+=	--with-mail-gid=${MAILMAN_MAILGROUP}
CONFIGURE_ARGS+=	--with-python=${PYTHONBIN}
CONFIGURE_ARGS+=	--with-username=${MAILMAN_USER}
CONFIGURE_ARGS+=	--with-var-prefix=${MAILMAN_DATADIR}
CONFIGURE_ARGS+=	--without-permcheck

# Put in externally invalid defaults (MESSAGE directs how to fix it)
CONFIGURE_ARGS+=	--with-mailhost=localhost
CONFIGURE_ARGS+=	--with-urlhost=localhost

post-patch:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/mailman.conf.dist \
		>${WRKDIR}/mailman.conf.dist
	${RM} -f ${WRKSRC}/[A-Z]*.orig

pre-install:
	${INSTALL} -d -o ${MAILMAN_USER} -g ${MAILMAN_GROUP} -m775 ${EXECDIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EXECDIR}/support

post-install:
	cd ${WRKSRC} && for i in [A-IN-U]*; do \
		${INSTALL_DATA} $$i ${DOCDIR}/; \
	done
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKDIR}/mailman.conf.dist ${EGDIR}/mailman.conf
	${CHOWN} -R root:${MAILMAN_GROUP} ${EXECDIR}
	${CHMOD} -R g-w ${EXECDIR}
	${CHMOD} g+s ${EXECDIR}/cgi-bin/*

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
