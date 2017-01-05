# $NetBSD: Makefile,v 1.29 2017/01/05 17:22:09 roy Exp $

DISTNAME=	ucblogo
PKGNAME=	${DISTNAME}-6.0
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.berkeley.edu/~bh/downloads/
# Not at GNU mirrors yet
# ${MASTER_SITE_GNU:=non-gnu/ucblogo/}
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://http.cs.berkeley.edu/~bh/logo.html
COMMENT=	Brian Harvey's logo language interpreter

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MAKE_FILE=	makefile
BUILD_TARGET=	# empty
GNU_CONFIGURE=	yes
# otherwise ./configure might find wxgtk
CONFIGURE_ARGS+=	--wx-disable
# otherwise ./configure guesses -L incorrectly
LIBS+=		-L${X11BASE}/lib

USE_TOOLS+=	makeinfo
INSTALLATION_DIRS=	info
INFO_FILES=	yes

post-extract:
	${RM} ${WRKSRC}/config.cache
	${RM} -rf ${WRKSRC}/csls/CVS

BUILDLINK_DEPMETHOD.libXt=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
