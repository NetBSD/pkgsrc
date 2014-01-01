# $NetBSD: Makefile,v 1.71 2014/01/01 11:52:21 wiz Exp $
#

DISTNAME=	coq-8.4pl2
PKGREVISION=	11
CATEGORIES=	lang math
MASTER_SITES=	http://coq.inria.fr/distrib/V${PKGVERSION_NOREV}/files/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	-mandir ${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-configdir ${PKG_SYSCONFDIR}/xdg/coq
CONFIGURE_ARGS+=	-docdir ${PREFIX}/share/doc/coq
CONFIGURE_ARGS+=	-coqdocdir ${PREFIX}/share/texmf-dist/tex/latex/coq
BUILD_TARGET=		world

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.10

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64") || \
    (${MACHINE_ARCH} == "arm")
PLIST.opt=	yes
PLIST_SUBST+=	COQIDE_TYPE="opt"
.else
PLIST_SUBST+=	COQIDE_TYPE="byte"
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

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
# See PR# 28772 as the above should work but it appears to be ignored
# so we set it explicitly below not to stip installed binaries.
_STRIPFLAG_CC=
_STRIPFLAG_INSTALL=
.endif

REPLACE_SH=	configure install.sh
INSTALL_ENV+=	COQINSTALLPREFIX=${DESTDIR}

PLIST_VARS=		coqide opt natdynlink doc

.include "options.mk"

EGDIR=		${PREFIX}/share/coq/examples
CONF_FILES=	${EGDIR}/coqide-gtk2rc ${PKG_SYSCONFDIR}/xdg/coq/coqide-gtk2rc

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../lang/camlp5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
