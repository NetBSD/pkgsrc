# $NetBSD: Makefile,v 1.30 2024/06/08 19:12:33 schmonz Exp $
#

DISTNAME=		etckeeper_1.18.21
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		https://git.joeyh.name/index.cgi/etckeeper.git/snapshot/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://etckeeper.branchable.com/
COMMENT=		Store /etc in git, mercurial, bzr or darcs
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		# none
USE_TOOLS+=		gawk perl:run

NO_BUILD=		yes
AUTO_MKDIRS=		yes

BUILD_DEFS+=		VARBASE

.include "cf-files.mk"

PKG_SYSCONFSUBDIR=	etckeeper
MAKE_DIRS+=		${VARBASE}/cache/etckeeper
MAKE_DIRS+=		${PKG_SYSCONFDIR}
MAKE_DIRS+=		${CF_FILES:H:O:u:S@^@${PKG_SYSCONFDIR}/@}

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
SUBST_STAGE.config=	do-configure
SUBST_FILES.config+=	etckeeper etckeeper.8
SUBST_FILES.config+=	list-installed.d/50list-installed
SUBST_FILES.config+=	pre-commit.d/20warn-problem-files
SUBST_FILES.config+=	pre-commit.d/30store-metadata
SUBST_FILES.config+=	commit.d/50vcs-commit
SUBST_FILES.config+=	pre-install.d/10packagelist
SUBST_FILES.config+=	post-install.d/50vcs-commit
SUBST_FILES.config+=	bash_completion zsh_completion
SUBST_FILES.config+=	daily
SUBST_VARS.config+=	PREFIX VARBASE EGREP PERL5
SUBST_VARS.config+=	PKG_SYSCONFBASEDIR PKG_SYSCONFDIR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/etckeeper ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etckeeper.conf ${DESTDIR}${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/daily ${DESTDIR}${EGDIR}
	for file in ${CF_FILES}; do					\
	  ${INSTALL_DATA} ${WRKSRC}/$${file} ${DESTDIR}${EGDIR}/$${file} ;\
	done
	${RM} -f ${DESTDIR}${EGDIR}/*.d/*.orig
	${INSTALL_MAN} ${WRKSRC}/etckeeper.8 \
					${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README.md \
			${DESTDIR}${PREFIX}/share/doc/etckeeper/README.md
	${INSTALL_DATA} ${WRKSRC}/bash_completion \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/etckeeper
	${INSTALL_DATA} ${WRKSRC}/zsh_completion \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_etckeeper

gen-cf-files: .PHONY
	{ \
	${ECHO} '# $$''NetBSD$$'; \
	${ECHO} '#'; \
	(cd ${WRKSRC} && ${LS} -1 *.d/*) \
	| ${AWK} '!/\.orig$$/ { print "CF_FILES+=\t" $$0 }'; \
	} >cf-files.mk

.include "../../mk/bsd.pkg.mk"
