# $NetBSD: Makefile,v 1.1 2020/02/28 22:16:01 plunky Exp $

DISTNAME=	harmbase2-20191229
CATEGORIES=	math
MASTER_SITES=	https://flaterco.com/files/xtide/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://flaterco.com/
COMMENT=	Harmonic constant management system
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=		fix-bash
SUBST_STAGE.fix-bash=	pre-configure
SUBST_FILES.fix-bash=	scripts/Debian.sh
SUBST_SED.fix-bash=	-e 's,==,=,'

REPLACE_SH=	scripts/*.sh
REPLACE_RUBY=	scripts/*.rb

DEPENDS+=	${RUBY_PKGPREFIX}-pg>=1.1.0:../../databases/ruby-pg

.include "../../databases/libtcd/buildlink3.mk"
.include "../../devel/libdstr/buildlink3.mk"
.include "../../lang/ruby/replace.mk"
.include "../../math/congen/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
