# $NetBSD: Makefile,v 1.30 2023/12/07 18:32:25 wiz Exp $

DISTNAME=	nickle-2.95
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.readline}

# suppress detection of DOCBOOK
CONFIGURE_ENV+=	ac_cv_path_DOCBOOK2PDF=

TEST_TARGET=	check

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
