# $NetBSD: Makefile,v 1.147 2022/08/11 05:08:54 gutteridge Exp $

DISTNAME=	coq-8.15.2
PKGREVISION=	2
CATEGORIES=	lang math
MASTER_SITES=	${MASTER_SITE_GITHUB:=coq/}
GITHUB_TAG=	V${PKGVERSION_NOREV:S/_/+/}

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	https://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV:S/+/-/}

USE_TOOLS+=		bash
USE_TOOLS+=		gmake
OCAML_USE_FINDLIB=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-configdir ${PKG_SYSCONFDIR}/xdg/coq
CONFIGURE_ARGS+=	-docdir ${PREFIX}/share/doc/coq
BUILD_TARGET=		world

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=4.05

# datestamp for reproducible builds (this ends up in compiled proofs)
# Use the upstream release date plus (arbitrarily) 11 days, the latter
# being a venture to hopefully avoid accepting compiled proof files from
# elsewhere that likely are not in fact compatible.
MAKE_ENV+=		SOURCE_DATE_EPOCH=20220611

.include "../../mk/bsd.prefs.mk"
.include "../../lang/ocaml/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
COQIDE_TYPE=		opt
CONFIGURE_ARGS+=	-native-compiler ondemand
UNLIMIT_RESOURCES+=	stacksize # compilation of some files needs this
BUILD_TARGET=		world
.else
COQIDE_TYPE=		byte
CONFIGURE_ARGS+=	-native-compiler no
BUILD_TARGET=		byte
INSTALL_TARGET=		install-byte
.endif
PLIST_SUBST+=		COQIDE_TYPE=${COQIDE_TYPE}

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

REPLACE_SH=		configure install.sh
REPLACE_INTERPRETER=	python
REPLACE.python.old=	python3
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	tools/TimeFileMaker.py \
			tools/make-both-single-timing-files.py \
			tools/make-both-time-files.py \
			tools/make-one-time-file.py

INSTALL_ENV+=	COQINSTALLPREFIX=${DESTDIR}

PLIST_VARS+=		coqide natdynlink doc

.include "options.mk"

EGDIR=		${PREFIX}/share/coq/examples
#CONF_FILES=	{EGDIR}/coqide-gtk2rc ${PKG_SYSCONFDIR}/xdg/coq/coqide-gtk2rc

# Pull in dune explicitly instead of setting OCAML_USE_DUNE above,
# because the latter causes pkgsrc to automagically run dune instead
# of make for the build and that isn't what you're supposed to do.
.include "../../devel/ocaml-dune/buildlink3.mk"

# Docs say at least 1.10 is required.
BUILDLINK_API_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.10

.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
