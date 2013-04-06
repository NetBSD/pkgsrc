# $NetBSD: Makefile,v 1.27 2013/04/06 20:27:19 rodent Exp $
#

DISTNAME=	pcl-cvs-2.9.9
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel scm
MASTER_SITES=	# ftp://rum.cs.yale.edu/pub/monnier/pcl-cvs/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Front-end to CVS for emacs

DEPENDS+=	emacs20-elib>=1.0:../../devel/emacs20-elib

CONFLICTS=	emacs-21.*
CONFLICTS+=	emacs21

EMACS_VERSIONS_ACCEPTED=	emacs20

.include "../../editors/emacs/modules.mk"

.if !((${EMACS_FLAVOR} == "emacs") && (${EMACS_VERSION_MAJOR} == "20"))
PKG_FAIL_REASON+=	"${PKGNAME} is only for emacs20"
.endif

MAKE_ENV+=	PREFIX=${DESTDIR:Q}${PREFIX:Q}
BUILD_TARGET=	default
INFO_FILES=	yes
MESSAGE_SUBST+=	EMACS_LISPPREFIX=${EMACS_LISPPREFIX:Q}

.include "../../mk/bsd.pkg.mk"
