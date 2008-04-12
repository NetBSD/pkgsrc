# $NetBSD: Makefile,v 1.33 2008/04/12 14:44:05 taca Exp $
#

DISTNAME=	jisx0208fonts-200301316
PKGREVISION=	2
CATEGORIES=	fonts x11 japanese
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
COMMENT=	Meta-package including X11 BDF fonts for JIS X0208 standard and more

META_PACKAGE=	yes

.include "../../mk/bsd.prefs.mk"

USE_NON_SQUARE?= NO
USE_KANAME?= NO

DEPENDS+=	ja-elisat>=1.0:../../fonts/ja-elisat
DEPENDS+=	ja-kappa20>=0.394:../../fonts/ja-kappa20
DEPENDS+=	ja-naga10>=1.1:../../fonts/ja-naga10
DEPENDS+=	ja-shinonome>=0.9.11:../../fonts/ja-shinonome
.if ${USE_NON_SQUARE} == YES
DEPENDS+=	ja-elisau>=1.0:../../fonts/ja-elisau
.endif
.if ${USE_KANAME} == YES
DEPENDS+=	ja-kaname>=0.0.0.20030112:../../fonts/ja-kaname
.endif

.include "../../mk/bsd.pkg.mk"
