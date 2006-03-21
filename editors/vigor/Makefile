# $NetBSD: Makefile,v 1.26 2006/03/21 18:53:59 minskim Exp $
#

DISTNAME=	vigor-0.016
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vigor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vigor.sourceforge.net/
COMMENT=	nvi with excessive online "help"

CONFLICTS+=	nvi-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	build
CONFIGURE_ENV+=	TCLCONFIG_SH=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=	vi_cv_path_shell=${TOOLS_SH:Q}
CONFIGURE_ARGS+=--with-x
#		--enable-perlinterp \
#		--disable-curses \
#		--disable-db \
#		--disable-re
USE_TOOLS+=	sh
BUILD_DIRS=	${CONFIGURE_DIRS}

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.if exists(/usr/include/sys/queue.h)
# this file obscures the system header
post-patch:
	${RM} -f ${WRKSRC}/include/sys/queue.h
.endif

post-build:
	nroff -mandoc ${WRKSRC}/docs/USD.doc/vi.man/vi.1 >${WRKSRC}/docs/USD.doc/vi.man/vi.0

.include "../../mk/bsd.pkg.mk"
