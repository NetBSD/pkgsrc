# $NetBSD: Makefile,v 1.18 2022/08/09 12:08:35 jperkin Exp $

DISTNAME=	diction-1.13
CATEGORIES=	textproc
MASTER_SITES=	http://www.moria.de/~michael/diction/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/diction/diction.html
COMMENT=	GNU version of diction and style
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake msgfmt

USE_FEATURES+=		getopt_long regcomp snprintf

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
