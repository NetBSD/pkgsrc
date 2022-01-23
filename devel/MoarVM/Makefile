# $NetBSD: Makefile,v 1.34 2022/01/23 13:18:37 mef Exp $

DISTNAME=	MoarVM-2021.12
CATEGORIES=	devel perl6
MASTER_SITES=	http://www.moarvm.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.moarvm.org/
COMMENT=	Virtual machine for Rakudo Perl 6
LICENSE=	artistic-2.0

DEPENDS+=	zstd>=1.0.0:../../archivers/zstd

USE_TOOLS+=		perl gmake
USE_LANGUAGES=		c c++
NOT_PAX_MPROTECT_SAFE=	bin/moar

HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib
CONFIGURE_ENV+=		LDFLAGS=${LDFLAGS:Q}
CONFIGURE_SCRIPT=	Configure.pl
CONFIGURE_ARGS=		--prefix=${PREFIX:Q} \
			--has-libatomic_ops \
			--has-libffi \
			--has-libuv \
			--has-libtommath

# skip portability check for release target
# The [[ is only used for producing a release.
CHECK_PORTABILITY_SKIP+=	build/Makefile.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST_SUBST+=	EXT=dylib
.else
PLIST_SUBST+=	EXT=so
.endif

.include "../../devel/libatomic_ops/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
