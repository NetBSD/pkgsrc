# $NetBSD: Makefile,v 1.3 2003/01/16 02:20:47 uebayasi Exp $

DISTNAME=		guile-1.4.1
PKGNAME=		guile14-1.4.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=guile/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/guile/guile.html
COMMENT=		GNU's Ubiquitous Intelligent Language for Extension

# XXX Conflicts even with older (<1.6) packages because of PKGNAME change.
CONFLICTS=		guile-[0-9]*

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
USE_NCURSES=	# termlib not in libtermcap on Solaris, use the ncurses one
.  include "../../devel/ncurses/buildlink2.mk"
.endif

.include "../../devel/libtool/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"

PREFIX=			${LOCALBASE}/guile/1.4
