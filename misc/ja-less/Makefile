# $NetBSD: Makefile,v 1.5 2005/03/24 21:12:57 wiz Exp $

DISTNAME=	less-358
PKGNAME=	ja-${DISTNAME}
PKGREVISION=	1
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

.include "../../mk/bsd.pkg.mk"
