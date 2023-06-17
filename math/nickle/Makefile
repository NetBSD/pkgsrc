# $NetBSD: Makefile,v 1.26 2023/06/17 11:25:19 riastradh Exp $

DISTNAME=	nickle-2.91
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

USE_TOOLS+=	autoconf automake autoreconf
TOOL_DEPENDS+=	autoconf-archive>=0:../../devel/autoconf-archive

GNU_CONFIGURE=	yes

# suppress detection of DOCBOOK
CONFIGURE_ENV+=	ac_cv_path_DOCBOOK2PDF=

CONFIGURE_ARGS+=CC_FOR_BUILD=${NATIVE_CC:Q}

TEST_TARGET=	check

pre-configure:
	${RUN} cd ${WRKSRC} && autoreconf -fi

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
