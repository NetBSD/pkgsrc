# $NetBSD: Makefile,v 1.3 2004/01/24 13:51:14 grant Exp $
#

DISTNAME=	coq-7.4
PKGREVISION=	1
CATEGORIES=	lang math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/coq/V7.4/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs

USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	-reals all
ALL_TARGET=	world

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || (${MACHINE_ARCH} == "sparc")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.endif

.include "../../lang/ocaml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
