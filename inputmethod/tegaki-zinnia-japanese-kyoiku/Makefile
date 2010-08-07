# $NetBSD: Makefile,v 1.1.1.1 2010/08/07 12:59:01 obache Exp $
#

DISTNAME=	tegaki-zinnia-japanese-kyoiku-0.3
CATEGORIES=	inputmethod japanese
MASTER_SITES=	http://www.tegaki.org/releases/0.3/models/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.tegaki.org/
COMMENT=	Tegaki project handwriting model for Zinnia-Japanese (kyoiku)
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	share/tegaki/models/zinnia

INSTALL_MAKE_FLAGS+=	installpath=${DESTDIR}${PREFIX}/share/tegaki/models/zinnia

.include "../../mk/bsd.pkg.mk"
