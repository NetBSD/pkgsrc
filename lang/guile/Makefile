# $NetBSD: Makefile,v 1.51 2004/02/14 17:21:43 jlam Exp $

DISTNAME=		guile-1.6.4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

CONFLICTS=		guile14<1.4.1nb1

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_GNU_READLINE=	YES

USE_MAKEINFO=		YES
INFO_FILES=		guile.info guile-tut.info goops.info r5rs.info

TEST_DIRS=		${WRKSRC}
TEST_TARGET=		check

.include "../../devel/libtool/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
