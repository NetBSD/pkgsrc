# $NetBSD: Makefile,v 1.10 2004/12/03 15:14:55 wiz Exp $
#

DISTNAME=	pcl-cvs-2.9.9
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://rum.cs.yale.edu/pub/monnier/pcl-cvs/

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=	Front-end to CVS for emacs

DEPENDS+=	emacs20-elib>=1.0:../../devel/emacs20-elib

CONFLICTS=	emacs-21.*
CONFLICTS+=	emacs21

EMACS_VERSIONS_ACCEPTED=	emacs20

.include "../../mk/emacs.mk"

MAKE_ENV+=	PREFIX=${PREFIX}
BUILD_TARGET= 	default
INFO_FILES=	pcl-cvs.info
MESSAGE_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:Q}

.include "../../mk/bsd.pkg.mk"
