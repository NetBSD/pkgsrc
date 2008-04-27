# $NetBSD: Makefile,v 1.21 2008/04/27 10:46:16 tonio Exp $
#

DISTNAME=	coq-8.1pl3
PKGREVISION=	1
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/coq/V8.1pl3/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs

USE_TOOLS+=		gmake
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	-reals all
BUILD_TARGET=		world

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.09

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
	(${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.endif

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
# See PR# 28772 as the above should work but it appears to be ignored
# so we set it explicitly below not to stip installed binaries.
_STRIPFLAG_CC=
_STRIPFLAG_INSTALL=
.endif

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
