# $NetBSD: Makefile,v 1.7 2004/12/24 17:21:01 jmmv Exp $
#

DISTNAME=	coq-7.4
PKGREVISION=	3
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/coq/V7.4/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	-reals all
BUILD_TARGET=	world

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
