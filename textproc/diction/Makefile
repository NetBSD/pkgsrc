# $NetBSD: Makefile,v 1.7 2006/02/05 23:11:01 joerg Exp $

DISTNAME=	diction-1.08
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.moria.de/~michael/diction/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/diction/diction.html
COMMENT=	GNU version of diction and style

BUILD_USES_MSGFMT=	YES

USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
