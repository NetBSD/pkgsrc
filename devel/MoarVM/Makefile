# $NetBSD: Makefile,v 1.22 2020/10/31 12:20:45 mef Exp $

DISTNAME=	MoarVM-2020.10
CATEGORIES=	devel perl6
MASTER_SITES=	http://www.moarvm.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.moarvm.org/
COMMENT=	Virtual machine for Rakudo Perl 6
LICENSE=	artistic-2.0

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
