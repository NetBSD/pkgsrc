# $NetBSD: Makefile,v 1.47 2003/11/26 22:13:58 dmcmahill Exp $

DISTNAME=		guile-1.6.3
#PKGREVISION=		1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

CONFLICTS=		guile14<1.4.1nb1

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/guile-readline/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libltdl/libtool

USE_GNU_READLINE=	YES

USE_MAKEINFO=		YES
INFO_FILES=		guile.info guile-tut.info goops.info r5rs.info

TEST_DIRS=		${WRKSRC}
TEST_TARGET=		check

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
