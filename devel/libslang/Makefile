# $NetBSD: Makefile,v 1.39 2003/03/14 23:53:01 jschauma Exp $
#

DISTNAME=	slang-1.4.8
PKGNAME=	lib${DISTNAME}
SVR4_PKGNAME=	lslan
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/ \
		http://gd.tuwien.ac.at/editors/davis/slang/v1.4/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/slang/v1.4/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slang/v1.4/ \
		ftp://ftp.plig.org/pub/slang/v1.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=    	packages@netbsd.org
HOMEPAGE=	http://www.s-lang.org/
COMMENT=	Routines for rapid alpha-numeric terminal applications development

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
GNU_CONFIGURE=		# defined

CONFIG_GUESS_OVERRIDE=	${WRKSRC}/autoconf/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/autoconf/config.sub

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/slang
	${MV} ${PREFIX}/share/doc/slang/slangdoc.html \
		${PREFIX}/share/doc/html/slang

.include "../../mk/bsd.prefs.mk"

# Debian doesn't have ltermcap, use ncurses instead
.if ${OPSYS} == "Linux" && ${LOWER_VENDOR} == "debian"
post-patch:
	${SED} -e 's/ -ltermcap / /' ${WRKSRC}/src/Makefile.in > \
		${WRKSRC}/src/Makefile.in.tmp &&		\
		${MV} ${WRKSRC}/src/Makefile.in.tmp ${WRKSRC}/src/Makefile.in

. include "../../devel/ncurses/buildlink2.mk"
.endif

.include "../../mk/bsd.pkg.mk"
