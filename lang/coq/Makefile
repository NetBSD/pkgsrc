# $NetBSD: Makefile,v 1.8 2005/02/05 11:19:02 adrianp Exp $
#

DISTNAME=	coq-8.0pl2
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/coq/V8.0pl2/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs

USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	-reals all
BUILD_TARGET=		world

BUILDLINK_DEPENDS.ocaml+=       ocaml>=3.06

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
	(${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.endif

.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=     yes
# See PR# 28772 as the above should work but it appears to be ignored
# so we set it explicitly below not to stip installed binaries.
_STRIPFLAG_CC=
_STRIPFLAG_INSTALL=
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
