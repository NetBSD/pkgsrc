# $NetBSD: Makefile,v 1.2.2.2 2002/06/23 18:44:51 jlam Exp $
#

DISTNAME=	pcl-cvs-2.9.9
CATEGORIES=	devel
MASTER_SITES=	ftp://rum.cs.yale.edu/pub/monnier/pcl-cvs/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=
COMMENT=	front-end to CVS for emacs

DEPENDS+= 	emacs-20.*:../../editors/emacs
DEPENDS+=	elib>=1.0:../../devel/elib

CONFLICTS=	emacs-21.*
CONFLICTS+=	emacs21

.include "../../mk/bsd.prefs.mk"

LISPDIR=	share/emacs/site-lisp/pcl-cvs

MAKE_ENV+=	PREFIX=${PREFIX}
ALL_TARGET= 	default
INFO_FILES=	pcl-cvs.info

PLIST_SUBST+=	LISPDIR=${LISPDIR}
MESSAGE_SUBST+=	LISPDIR=${LISPDIR}

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
