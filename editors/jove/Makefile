# $NetBSD: Makefile,v 1.9 2005/03/15 04:51:19 tv Exp $
#

DISTNAME=	jove4.16.0.63
PKGNAME=	${DISTNAME:S/jove/jove-/}
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cs.toronto.edu/pub/hugh/jove-dev/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Small emacs-style editor, but lacks the LISP engine

NO_CONFIGURE=	yes
USE_BUILDLINK3=	YES

MAKE_ENV+=	ROOT_GROUP=${ROOT_GROUP:Q}
MAKE_ENV+=	ROOT_USER=${ROOT_USER:Q}
MAKE_FLAGS+=	NROFF=${NROFF:Q}

.include "../../mk/nroff.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
