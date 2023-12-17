# $NetBSD: Makefile,v 1.8 2023/12/17 16:04:51 zafer Exp $

DISTNAME=	atool-0.39.0
PKGREVISION=	5
CATEGORIES=	archivers
MASTER_SITES=	https://download.savannah.gnu.org/releases/atool/

MAINTAINER=	mcy@lm7.fr
HOMEPAGE=	https://www.nongnu.org/atool/
COMMENT=	Manage file archives of various types
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none (perl)
USE_TOOLS+=	gmake perl
REPLACE_PERL=	atool

.include "../../mk/bsd.pkg.mk"
