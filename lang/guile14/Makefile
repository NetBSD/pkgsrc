# $NetBSD: Makefile,v 1.7 2003/06/02 01:19:02 jschauma Exp $

DISTNAME=		guile-1.4.1
PKGNAME=		guile14-1.4.1
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
NO_MTREE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/guile-readline/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libltdl/libtool

USE_GNU_READLINE=	YES

INFO_FILES=		guile.info

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX=			${LOCALBASE}/guile/1.4
