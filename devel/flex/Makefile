# $NetBSD: Makefile,v 1.49 2016/08/11 00:41:54 mef Exp $

DISTNAME=	flex-2.6.0
CATEGORIES=	devel lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=flex/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/westes/flex
COMMENT=	Fast clone of lex(1), the lexical scanner generator
LICENSE=	2-clause-bsd

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gm4:run
GNU_CONFIGURE=		yes
INFO_FILES=		yes

TEST_TARGET=		check
LIBS.SunOS+=		-lm

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
