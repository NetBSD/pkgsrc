# $NetBSD: Makefile,v 1.13 2015/02/01 16:36:32 taca Exp $

DISTNAME=	rcsparse-${VERS}
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	-https://github.com/corecode/rcsparse/archive/${REVISION}.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/corecode/rcsparse/
COMMENT=	RCS parsing library for Ruby
LICENSE=	gnu-agpl-v3

# This is our own version.
VERS=		0.0.0.47
REVISION=	60871fde79db91aed56b3974e8ebc829342d18e8

WRKSRC=		${WRKDIR}/rcsparse-${REVISION}
USE_RUBY_EXTCONF=	yes

post-extract:
	cd ${WRKSRC}; find . -type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
