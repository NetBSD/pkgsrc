# $NetBSD: Makefile,v 1.48 2012/10/02 20:11:37 asau Exp $
#

DISTNAME=	coq-8.3pl1
PKGREVISION=	14
CATEGORIES=	lang math
MASTER_SITES=	http://coq.inria.fr/distrib/V8.3pl1/files/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-emacslib ${PREFIX}/share/emacs/site-lisp
BUILD_TARGET=		world

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.10

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
	(${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.endif

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.  if !empty(MACHINE_PLATFORM:MLinux-*-*) || \
      !empty(MACHINE_PLATFORM:MDragonFly-*-*) || \
      !empty(MACHINE_PLATFORM:MFreeBSD-*-*) || \
      !empty(MACHINE_PLATFORM:MNetBSD-*-*)
PLIST_SRC+=	${PKGDIR}/PLIST.natdynlink
.  endif
.endif

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
# See PR# 28772 as the above should work but it appears to be ignored
# so we set it explicitly below not to stip installed binaries.
_STRIPFLAG_CC=
_STRIPFLAG_INSTALL=
.endif

REPLACE_SH=	configure install.sh
INSTALL_ENV+=	COQINSTALLPREFIX=${DESTDIR}

PLIST_VARS=		coqide
PKG_OPTIONS_VAR=	PKG_OPTIONS.coq
PKG_SUPPORTED_OPTIONS=	coqide
.include "../../mk/bsd.options.mk"
.if !empty(PKG_OPTIONS:Mcoqide)
.include "../../x11/lablgtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
PLIST.coqide=		yes
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/camlp5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
