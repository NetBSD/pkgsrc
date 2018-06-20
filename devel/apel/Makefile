# $NetBSD: Makefile,v 1.37 2018/06/20 11:57:46 ryoon Exp $

DISTNAME=	apel-10.8.0.20170122
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wanderlust/}
GITHUB_PROJECT=	apel
GITHUB_TAG=	339eb28ffae3165255a79de9b1fd362f43cd37c3

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://git.chise.org/elisp/apel/
COMMENT=	Portable Emacs library
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

INSTALLATION_DIRS+=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/apel
INSTALLATION_DIRS+=	${EMACS_LISPPREFIX:C|^${PREFIX}/||}/emu

PLIST_SRC=	${PKGDIR}/PLIST.${EMACS_FLAVOR}
BUILD_TARGET=	${BUILD_TARGET.${EMACS_FLAVOR}}
INSTALL_TARGET=	${INSTALL_TARGET.${EMACS_FLAVOR}}
MAKE_FLAGS+=	EMACS=${EMACS_FLAVOR:Q}
MAKE_FLAGS+=	LISPDIR=${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	VERSION_SPECIFIC_LISPDIR=${EMACS_LISPPREFIX:Q}
MAKE_FLAGS+=	${MAKE_FLAGS.${EMACS_FLAVOR}}

# apel is included in xemacs-packages
EMACS_VERSIONS_ACCEPTED=	emacs25 emacs25nox emacs21 emacs21nox emacs20
EMACS_VERSIONS_ACCEPTED+=	emacs26 emacs26nox

BUILD_TARGET.emacs=	elc
BUILD_TARGET.xemacs=	package
INSTALL_TARGET.emacs=	install
INSTALL_TARGET.xemacs=	install-package
MAKE_FLAGS.emacs=
MAKE_FLAGS.xemacs=	PACKAGEDIR=${EMACS_LISPPREFIX:C|/lisp$||}

.include "../../editors/emacs/modules.mk"

PLIST_VARS+=	emacs23 emacs19
.if empty(EMACS_TYPE:Mxemacs)
.  if !empty(EMACS_TYPE:Memacs2[3-9]*)
PLIST.emacs23=	yes
.  else
PLIST.emacs19=	yes
.  endif
.endif

# Pkgsrc developers should run "install" without this and check if PLIST is
# correct.  Users just need to install files.
do-install: plist
	cd ${WRKSRC};							\
	for subdir in emu apel; do					\
		grep -v '^@' ${PLIST} | grep "/site-lisp/$$subdir/" |	\
		while read file; do					\
			file=$$( basename $$file );			\
			${INSTALL_DATA} $$file				\
			    ${DESTDIR}${EMACS_LISPPREFIX}/$$subdir/$$file; \
		done							\
	done

.include "../../mk/bsd.pkg.mk"
