# $NetBSD: Makefile,v 1.3 2004/12/12 23:33:29 recht Exp $
# FreeBSD Id: Makefile,v 1.13 1998/07/17 20:36:13 steve Exp
#

DISTNAME=	less-358
PKGNAME=	ja-${DISTNAME}
CATEGORIES=	japanese misc
MASTER_SITES=	${MASTER_SITE_GNU:=less/}

PATCH_SITES=	http://www.io.com/~kazushi/less/
PATCHFILES=	less-358-iso254.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	komine@cc.meisei-u.ac.jp
HOMEPAGE=	http://www.io.com/~kazushi/less/
COMMENT=	Less + zcat + ISO-2022 - a pager similar to more and pg

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
