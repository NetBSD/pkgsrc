# $NetBSD: Makefile,v 1.23 2023/04/20 10:13:41 tnn Exp $

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.include "../../devel/readline/buildlink3.mk"
.else
.include "../../mk/readline.buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
