# $NetBSD: Makefile,v 1.3 2003/01/10 14:39:58 wiz Exp $
#

DISTNAME=	pcl-cvs-2.9.9
CATEGORIES=	devel
MASTER_SITES=	ftp://rum.cs.yale.edu/pub/monnier/pcl-cvs/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=
COMMENT=	front-end to CVS for emacs

DEPENDS+=	${PKGNAME_PREFIX}elib>=1.0:../../devel/elib

CONFLICTS=	emacs-21.*
CONFLICTS+=	emacs21

EMACS_VERSIONS_ACCEPTED=	emacs20

.include "../../mk/emacs.mk"

MAKE_ENV+=	PREFIX=${PREFIX}
ALL_TARGET= 	default
INFO_FILES=	pcl-cvs.info
MESSAGE_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:Q}

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
