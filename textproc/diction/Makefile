# $NetBSD: Makefile,v 1.9 2006/04/13 18:23:38 jlam Exp $

DISTNAME=	diction-1.08
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.moria.de/~michael/diction/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/diction/diction.html
COMMENT=	GNU version of diction and style

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		msgfmt

GNU_CONFIGURE=		YES

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
