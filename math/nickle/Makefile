# $NetBSD: Makefile,v 1.21 2023/04/18 21:31:08 wiz Exp $

DISTNAME=	nickle-2.91
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

GNU_CONFIGURE=	yes

# suppress detection of DOCBOOK
CONFIGURE_ENV+=	ac_cv_path_DOCBOOK2PDF=

TEST_TARGET=	check

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
