# $NetBSD: Makefile,v 1.32 2024/01/13 04:25:39 riastradh Exp $

DISTNAME=	nickle-2.96
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

USE_TOOLS+=	autoconf automake autoreconf
TOOL_DEPENDS+=	autoconf-archive>=0:../../devel/autoconf-archive

pre-configure:
	@${STEP_MSG} Autoreconf for Makefile.am patch
	${RUN} cd ${WRKSRC} && autoreconf -fi

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.editlinereadline}
CONFIGURE_ARGS+=	CC_FOR_BUILD=${NATIVE_CC:Q:U${CC:Q}}

# suppress detection of DOCBOOK
CONFIGURE_ENV+=	ac_cv_path_DOCBOOK2PDF=

TEST_TARGET=	check

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
