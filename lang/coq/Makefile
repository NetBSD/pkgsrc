# $NetBSD: Makefile,v 1.4 2004/04/28 05:06:28 snj Exp $
#

DISTNAME=	coq-7.4
PKGREVISION=	1
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
ALL_TARGET=	world

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.endif

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
