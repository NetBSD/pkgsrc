# $NetBSD: Makefile,v 1.14 2012/03/03 12:54:22 wiz Exp $

DISTNAME=	diction-1.11
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.moria.de/~michael/diction/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/diction/diction.html
COMMENT=	GNU version of diction and style

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt

USE_FEATURES+=		getopt_long regcomp snprintf

LIBS.SunOS+=		-lintl

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
