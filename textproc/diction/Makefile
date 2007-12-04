# $NetBSD: Makefile,v 1.10 2007/12/04 00:57:37 bjs Exp $

DISTNAME=	diction-1.11
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

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
