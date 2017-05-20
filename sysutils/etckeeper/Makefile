# $NetBSD: Makefile,v 1.8 2017/05/20 01:05:05 schmonz Exp $
#

DISTNAME=	etckeeper_1.18.5.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig$/.1/}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/e/etckeeper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://etckeeper.branchable.com/
COMMENT=	Store /etc in git, mercurial, bzr or darcs
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/.1$//}
USE_LANGUAGES=	# none
USE_TOOLS+=	sed perl:run

NO_CONFIGURE=	yes
NO_BUILD=	yes
AUTO_MKDIRS=	yes

BUILD_DEFS+=	VARBASE

ETCKEEPER_PATCH=etckeeper_1.18.5-1.diff.gz
PATCHFILES+=	${ETCKEEPER_PATCH}
SITES.${ETCKEEPER_PATCH}=	${MASTER_SITES}
PATCH_DIST_STRIP.${ETCKEEPER_PATCH}=	-p1

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
