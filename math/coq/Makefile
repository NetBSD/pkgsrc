# $NetBSD: Makefile,v 1.1.1.1 2003/03/22 18:20:54 kristerw Exp $
#

DISTNAME=	coq-7.4
CATEGORIES=	math lang
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/coq/V7.4/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://coq.inria.fr/
COMMENT=	Theorem prover which extracts programs from proofs

USE_GMAKE=	YES
USE_BUILDLINK2=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=	-prefix ${PREFIX}
CONFIGURE_ARGS+=	-emacslib ${PREFIX}/share/emacs/site-lisp
CONFIGURE_ARGS+=	-reals all
ALL_TARGET=	world

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386")
PLIST_SRC=	${PKGDIR}/PLIST.opt ${PKGDIR}/PLIST
.endif

.include "../../lang/ocaml/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
