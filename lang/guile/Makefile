# $NetBSD: Makefile,v 1.35 2003/01/16 02:31:30 uebayasi Exp $

DISTNAME=		guile-1.6.1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/guile-readline/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/libltdl/libtool

USE_GNU_READLINE=	YES

INFO_FILES=		guile.info

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_NCURSES=	# termlib not in libtermcap on Solaris, use the ncurses one
.  include "../../devel/ncurses/buildlink2.mk"
.endif

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
