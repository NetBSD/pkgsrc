# $NetBSD: Makefile,v 1.6 2022/01/21 16:34:59 nikita Exp $

DISTNAME=	guile-json-4.7.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.savannah.gnu.org/releases/guile-json/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/aconchillo/guile-json
COMMENT=	JSON module for Guile
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		# none
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		YES
GUILE_NEED_BOOTSTRAP=	YES

.include "../../lang/guile22/module.mk"
.include "../../mk/bsd.pkg.mk"
