# $NetBSD: Makefile,v 1.6 2001/07/23 10:21:12 jlam Exp $
#

DISTNAME=	smalltalk-1.95.4
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.smalltalk.org/versions/GNUSmalltalk.html
COMMENT=	GNU Smalltalk: A smalltalk-80 implementation

USE_GMAKE=		YES
USE_GNU_READLINE=	YES
USE_BUILDLINK_ONLY=	YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--with-included-regex
CONFIGURE_ARGS+=	--with-readline
CONFIGURE_ARGS+=	--with-tcl=${BUILDLINK_DIR}/lib
CONFIGURE_ARGS+=	--with-tk=${BUILDLINK_DIR}/lib

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/readline/buildlink.mk"
.include "../../lang/tcl/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
