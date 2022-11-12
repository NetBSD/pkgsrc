# $NetBSD: Makefile,v 1.3 2022/11/12 09:10:24 nikita Exp $

DISTNAME=	renameutils-0.12.0
CATEGORIES=	sysutils converters
MASTER_SITES=	https://download.savannah.gnu.org/releases/renameutils/

MAINTAINER=	mcy@lm7.fr
HOMEPAGE=	https://www.nongnu.org/renameutils/
COMMENT=	Rename files faster and more easily
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils

.include "options.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
