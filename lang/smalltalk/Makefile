# $NetBSD: Makefile,v 1.5 2001/07/10 22:37:36 mjl Exp $
#

DISTNAME=	smalltalk-1.95.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=	GNU Smalltalk: A smalltalk-80 implementation

CONFIGURE_ARGS=	--with-included-regex --with-readline=${PREFIX}
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_LIBTOOL=	YES
USE_GNU_READLINE=YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/readline/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
