# $NetBSD: Makefile,v 1.31 2002/08/26 20:28:14 tron Exp $

DISTNAME=		guile-1.4.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/guile-readline/libtool

USE_GNU_READLINE=	YES

INFO_FILES=		guile.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_NCURSES=	# termlib not in libtermcap on Solaris, use the ncurses one
.include "../../devel/ncurses/buildlink.mk"
.endif

post-configure:
	${RM} -rf ${WRKSRC}/libltdl
	${MKDIR} ${WRKSRC}/libltdl
	for FILE in ${LOCALBASE}/lib/libltdl.* 			\
	  ${LOCALBASE}/share/libtool/libltdl/*; do		\
	  ${LN} -s $$FILE ${WRKSRC}/libltdl;			\
	done

.include "../../devel/readline/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
