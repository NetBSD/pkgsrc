# $NetBSD: Makefile,v 1.1 2019/11/13 10:36:19 ng0 Exp $

DISTNAME=	guile-json-3.1.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.savannah.gnu.org/releases/guile-json/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/aconchillo/guile-json
COMMENT=	JSON module for Guile
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		# none
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
GUILE_NEED_BOOTSTRAP=	YES

.include "../../lang/guile22/module.mk"
.include "../../mk/bsd.pkg.mk"
