# $NetBSD: Makefile,v 1.14 2019/07/27 08:01:43 mef Exp $

DISTNAME=	rcsparse-${VERS}
CATEGORIES=	devel ruby
# no release tag placed yet
MASTER_SITES=	-https://github.com/corecode/rcsparse/archive/${REVISION}.zip
EXTRACT_SUFX=	.zip
# for 0.0.0.47, different (checksum) version may exist
DIST_SUBDIR=	rcsparse

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
