# $NetBSD: Makefile,v 1.25 2003/03/16 01:46:05 kei Exp $
#

DISTNAME=	jisx0208fonts-20301316
CATEGORIES=	fonts x11 japanese
MASTER_SITES=   # empty
DISTFILES=	# empty

MAINTAINER=	tech-pkg-ja@jp.netbsd.org
COMMENT=	meta-package including X11 BDF fonts for JIS X0208 standard and more

.include "../../mk/bsd.prefs.mk"

USE_NON_SQUARE?= NO
USE_KANAME?= NO

DEPENDS+=	ja-elisat>=1.0:../../fonts/ja-elisat
DEPENDS+=	ja-kappa20>=0.394:../../fonts/ja-kappa20
DEPENDS+=	ja-naga10>=1.1:../../fonts/ja-naga10
DEPENDS+=	ja-shinonome>=0.9.9:../../fonts/ja-shinonome
.if ${USE_NON_SQUARE} == YES
DEPENDS+=	ja-elisau>=1.0:../../fonts/ja-elisau
.endif
.if ${USE_KANAME} == YES
DEPENDS+=	ja-kaname>=0.0.0.20030112:../../fonts/ja-kaname
.endif

USE_X11BASE=	YES
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

do-install:	# do nothing

.include "../../mk/bsd.pkg.mk"
