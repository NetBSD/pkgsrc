# $NetBSD: Makefile,v 1.26 2015/10/11 07:02:39 ryoon Exp $

DISTNAME=	ucblogo
PKGNAME=	${DISTNAME}-6.0
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.berkeley.edu/~bh/downloads/
# Not at GNU mirrors yet
# ${MASTER_SITE_GNU:=non-gnu/ucblogo/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://http.cs.berkeley.edu/~bh/logo.html
COMMENT=	Brian Harvey's logo language interpreter

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_FILE=	makefile
BUILD_TARGET=	# empty
GNU_CONFIGURE=	yes
# otherwise ./configure guesses -L incorrectly
LIBS+=		-L${X11BASE}/lib

USE_TOOLS+=	makeinfo
INSTALLATION_DIRS=	info

post-extract:
	${RM} ${WRKSRC}/config.cache
	${RM} -rf ${WRKSRC}/csls/CVS

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
