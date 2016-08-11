# $NetBSD: Makefile,v 1.50 2016/08/11 03:23:44 mef Exp $

VERSION=	2.6.1
DISTNAME=	flex-${VERSION}
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=westes/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/westes/flex
COMMENT=	Fast clone of lex(1), the lexical scanner generator
LICENSE=	2-clause-bsd

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4:run	automake autoconf makeinfo gettext
GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check
LIBS.SunOS+=		-lm

BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

.include "../../mk/bsd.prefs.mk"

CFLAGS.AIX+=		-D_LINUX_SOURCE_COMPAT

.if ${OS_VARIANT} == "SCOOSR5"
LDFLAGS.SCO_SV+=	-lsocket
.endif

#.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash:build
REPLACE_BASH=		tests/testwrapper.sh tests/options.cn
USE_TOOLS+=		gmake	# bmake has problems with the test suite
#.endif

pre-configure:
	(cd ${WRKSRC}; ./autogen.sh)

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
