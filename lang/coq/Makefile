# $NetBSD: Makefile,v 1.177 2026/03/01 12:38:35 gdt Exp $

DISTNAME=	coq-8.20.1
PKGREVISION=	8
CATEGORIES=	lang math
MASTER_SITES=	${MASTER_SITE_GITHUB:=coq/}
GITHUB_TAG=	V${PKGVERSION_NOREV:S/_/+/}

MAINTAINER=	dholland@NetBSD.org
HOMEPAGE=	https://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV:S/+/-/}

# While the build is now mostly Dune-based there's still some gmake
# bits.
#
# Allegedly, building the dune package "coq" is the same as building
# "coq-core" and "coq-stdlib", it doesn't work: unless you explicitly
# build both, coqide fails.
#
# It is necessary to set INSTALL_UNSTRIPPED because opam/opaline
# doesn't distinguish scripts from bins and the infrastructure tells
# it to use INSTALL_PROGRAM; it will use the latter to install a
# Python script, and then strip chokes.
USE_TOOLS+=		bash
USE_TOOLS+=		gmake
OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-configdir ${PKG_SYSCONFDIR}/xdg/coq
CONFIGURE_ARGS+=	-docdir ${PREFIX}/share/doc/coq
DUNE_BUILD_PACKAGES=	coq-core coq-stdlib
OPAM_INSTALL_FILES=	coq-core coq-stdlib
INSTALL_UNSTRIPPED=	yes

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=4.05

# datestamp for reproducible builds (this ends up in compiled proofs)
# Use the upstream release date plus (arbitrarily) 11 days, the latter
# being a venture to hopefully avoid accepting compiled proof files from
# elsewhere that likely are not in fact compatible.
MAKE_ENV+=		SOURCE_DATE_EPOCH=20250127

PLIST_VARS+=		natdynlink

# This must come before ocaml.mk because it changes DUNE_BUILD_PACKAGES.
.include "options.mk"

.include "../../mk/bsd.prefs.mk"
.include "../../lang/ocaml/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
CONFIGURE_ARGS+=	-native-compiler ondemand
UNLIMIT_RESOURCES+=	stacksize # compilation of some files needs this
.else
CONFIGURE_ARGS+=	-native-compiler no
.endif

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.  if !empty(MACHINE_PLATFORM:MLinux-*-*) || \
      !empty(MACHINE_PLATFORM:MDragonFly-*-*) || \
      !empty(MACHINE_PLATFORM:MFreeBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MDarwin-*-*) || \
      !empty(MACHINE_PLATFORM:MNetBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MSunOS-*-*)
PLIST.natdynlink=	yes
.  endif
.endif

.include "../../lang/python/pyversion.mk"

REPLACE_INTERPRETER=	python
REPLACE.python.old=	python3
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python+=	tools/make-both-single-timing-files.py
REPLACE_FILES.python+=	tools/make-both-time-files.py
REPLACE_FILES.python+=	tools/make-one-time-file.py

# As of 8.20 it seems the best way to get things built is to do this
# explicitly as a separate step and then use OCAML_USE_DUNE. You can
# still build via the makefile, but then there's no way to install the
# results.
pre-build:
	${RUN} ${_ULIMIT_CMD} \
		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		gmake -j ${MAKE_JOBS:U1} dunestrap

# Upstream build changes as of 8.20 moved the stdlib. Since it's
# not uncommon to look at those by hand, plus there's the possibility
# of users having things pointing to it, symlink the old location.
post-install:
	${RUN} ${LN} -sf ocaml/site-lib/coq ${DESTDIR}${PREFIX}/lib/coq

# XXX this should be a TOOL_DEPENDS but things aren't set up that way
# Docs say at least 3.6.1.
BUILDLINK_API_DEPENDS.ocaml-dune+=	ocaml-dune>=3.6.1

# XXX this should be a TOOL_DEPENDS too
# Docs say at least 1.8.1
BUILDLINK_API_DEPENDS.ocaml-findlib+=	ocaml-findlib>=1.8.1

# Docs say at least 1.11 is required.
BUILDLINK_API_DEPENDS.ocaml-zarith+=	ocaml-zarith>=1.11

.include "../../math/ocaml-zarith/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
