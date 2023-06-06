# $NetBSD: Makefile,v 1.64 2023/06/06 12:40:37 riastradh Exp $

DISTNAME=	flex-2.6.4
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=westes/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/westes/flex
COMMENT=	Fast clone of lex(1), the lexical scanner generator
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

# wants stdbool
USE_LANGUAGES=		c99 c++

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4:run	gmake makeinfo gettext
GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check
LIBS.SunOS+=		-lm

.include "../../mk/bsd.prefs.mk"

CFLAGS.AIX+=		-D_LINUX_SOURCE_COMPAT

.if ${OS_VARIANT} == "SCOOSR5"
LDFLAGS.SCO_SV+=	-lsocket
.endif

# https://github.com/westes/flex/issues/219
CONFIGURE_ENV.NetBSD+=	ac_cv_func_reallocarray=no

# https://github.com/westes/flex/issues/241
CFLAGS.Linux+=		-D_GNU_SOURCE

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
