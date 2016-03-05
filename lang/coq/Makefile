# $NetBSD: Makefile,v 1.86 2016/03/05 11:28:43 jperkin Exp $
#

DISTNAME=	coq-8.5
PKGREVISION=	1
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
.include "../../mk/ocaml.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
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

REPLACE_SH=	configure install.sh
INSTALL_ENV+=	COQINSTALLPREFIX=${DESTDIR}

PLIST_VARS+=		coqide natdynlink doc

.include "options.mk"

EGDIR=		${PREFIX}/share/coq/examples
#CONF_FILES=	{EGDIR}/coqide-gtk2rc ${PKG_SYSCONFDIR}/xdg/coq/coqide-gtk2rc

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/camlp5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
