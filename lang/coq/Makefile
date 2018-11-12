# $NetBSD: Makefile,v 1.114 2018/11/12 03:52:26 ryoon Exp $
#

DISTNAME=	coq-8.8.1
PKGREVISION=	2
CATEGORIES=	lang math
MASTER_SITES=	${MASTER_SITE_GITHUB:=coq/}
GITHUB_TAG=	V${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	-mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-configdir ${PKG_SYSCONFDIR}/xdg/coq
CONFIGURE_ARGS+=	-docdir ${PREFIX}/share/doc/coq
CONFIGURE_ARGS+=	-coqdocdir ${PREFIX}/share/texmf-dist/tex/latex/coq

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.10

.include "../../mk/bsd.prefs.mk"
.include "../../mk/ocaml.mk"

PLIST_VARS+=	native
.if ${OCAML_USE_OPT_COMPILER} == "yes"
PLIST_SUBST+=	COQIDE_TYPE="opt"
PLIST.native=	yes
CONFIGURE_ARGS+=	-native-compiler yes
UNLIMIT_RESOURCES+=	stacksize # compilation of some files needs this
BUILD_TARGET=	world
.else
PLIST_SUBST+=	COQIDE_TYPE="byte"
CONFIGURE_ARGS+=	-native-compiler no
BUILD_TARGET=	byte
INSTALL_TARGET=	install-byte
.endif

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.  if !empty(MACHINE_PLATFORM:MLinux-*-*) || \
      !empty(MACHINE_PLATFORM:MDragonFly-*-*) || \
      !empty(MACHINE_PLATFORM:MFreeBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MDarwin-*-*) || \
      !empty(MACHINE_PLATFORM:MNetBSD-*-*)
PLIST.natdynlink=	yes
.  endif
.endif

.include "../../lang/python/pyversion.mk"

REPLACE_SH=	configure install.sh
REPLACE_INTERPRETER+=	python2 python
REPLACE.python.old=	python
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	tools/TimeFileMaker.py

REPLACE.python2.old=	python2
REPLACE.python2.new=	${PYTHONBIN}
REPLACE_FILES.python2=	tools/make-both-single-timing-files.py \
	tools/make-both-time-files.py \
	tools/make-one-time-file.py

INSTALL_ENV+=	COQINSTALLPREFIX=${DESTDIR}

PLIST_VARS+=		coqide natdynlink doc

.include "options.mk"

EGDIR=		${PREFIX}/share/coq/examples
#CONF_FILES=	{EGDIR}/coqide-gtk2rc ${PKG_SYSCONFDIR}/xdg/coq/coqide-gtk2rc

SUBST_CLASSES+=	fix-paths
SUBST_STAGE.fix-paths=	post-configure
SUBST_MESSAGE.fix-paths=	Remove buildlink references from Coq_config module
SUBST_FILES.fix-paths=	config/coq_config.ml
SUBST_SED.fix-paths=	-e "s,${BUILDLINK_DIR},${PREFIX},g"

.include "../../lang/camlp5/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
