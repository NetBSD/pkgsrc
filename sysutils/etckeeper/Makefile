# $NetBSD: Makefile,v 1.7 2017/05/18 21:19:08 schmonz Exp $
#

DISTNAME=	etckeeper_1.15
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/e/etckeeper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://etckeeper.branchable.com/
COMMENT=	Store /etc in git, mercurial, bzr or darcs
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/etckeeper
USE_LANGUAGES=	# none
USE_TOOLS+=	sed perl:run

NO_CONFIGURE=	yes
NO_BUILD=	yes
AUTO_MKDIRS=	yes

BUILD_DEFS+=	VARBASE

.include "cf-files.mk"

PKG_SYSCONFSUBDIR=	etckeeper
OWN_DIRS+=		${VARBASE}/cache/etckeeper
OWN_DIRS+=		${PKG_SYSCONFDIR}
OWN_DIRS+=		${CF_FILES:H:O:u:S@^@${PKG_SYSCONFDIR}/@}

EGDIR=			${PREFIX}/share/examples/etckeeper

CONF_FILES+=		${EGDIR}/etckeeper.conf ${PKG_SYSCONFDIR}/etckeeper.conf
.for file in ${CF_FILES:M*/README}
CONF_FILES+=		${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor
.for file in ${CF_FILES:N*/README}
CONF_FILES_PERMS+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file} \
				${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
.endfor

SUBST_CLASSES+=		config
SUBST_STAGE.config=	pre-install
SUBST_FILES.config+=	etckeeper
SUBST_FILES.config+=	etckeeper.8
SUBST_FILES.config+=	pre-install.d/10packagelist
SUBST_FILES.config+=	post-install.d/50vcs-commit
SUBST_FILES.config+=	bash_completion
SUBST_FILES.config+=	debian/cron.daily
SUBST_VARS.config+=	PKG_SYSCONFBASEDIR
SUBST_VARS.config+=	PKG_SYSCONFDIR
SUBST_VARS.config+=	VARBASE
SUBST_VARS.config+=	PREFIX

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/etckeeper ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etckeeper.conf ${DESTDIR}${EGDIR}
	for file in ${CF_FILES}; do					\
	  ${INSTALL_DATA} ${WRKSRC}/$${file} ${DESTDIR}${EGDIR}/$${file} ;\
	done
	${RM} -f ${DESTDIR}${EGDIR}/*.d/*.orig
	${INSTALL_SCRIPT} ${WRKSRC}/debian/cron.daily \
				${DESTDIR}${PREFIX}/libexec/etckeeper.daily
	${INSTALL_MAN} ${WRKSRC}/etckeeper.8 \
					${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README.md \
			${DESTDIR}${PREFIX}/share/doc/etckeeper/README.md
	${INSTALL_DATA} ${WRKSRC}/bash_completion \
			${DESTDIR}${PREFIX}/share/bash-completion.d/etckeeper

.PHONY:gen-cf-files
gen-cf-files:
	grep '[$$]NetBSD' >cf-files.mk
	${ECHO} '#'		>>cf-files.mk
	${SH} -c 'cd ${WRKSRC} && ${LS} -1 *.d/*' | 			\
	${SED} -e'/\.orig$$/d' -e's@^@CF_FILES+= @' >>cf-files.mk

.include "../../mk/bsd.pkg.mk"
