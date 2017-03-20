# $NetBSD: Makefile,v 1.16 2017/03/20 13:13:51 wiz Exp $

DISTNAME=	nickle-2.79
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

GNU_CONFIGURE=	yes

# suppress detection of DOCBOOK
CONFIGURE_ENV+=	ac_cv_path_DOCBOOK2PDF=

TEST_TARGET=	check

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
