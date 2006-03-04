# $NetBSD: Makefile,v 1.8 2006/03/04 21:30:45 jlam Exp $

DISTNAME=	diction-1.08
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.moria.de/~michael/diction/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/diction/diction.html
COMMENT=	GNU version of diction and style

BUILD_USES_MSGFMT=	YES

USE_PKGLOCALEDIR=	YES

GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
