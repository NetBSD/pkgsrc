# $NetBSD: Makefile,v 1.16 2005/01/22 02:35:44 minskim Exp $
#

DISTNAME=	vigor-0.016
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vigor/}

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://vigor.sourceforge.net/
COMMENT=	nvi with excessive online "help"

CONFLICTS+=	nvi-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/build
USE_X11=	yes
USE_BUILDLINK3=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x
#		--enable-perlinterp \
#		--disable-curses \
#		--disable-db \
#		--disable-re
CONFIGURE_ENV+=	TCLCONFIG_SH=${TCLCONFIG_SH:Q}

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

.if exists(/usr/include/sys/queue.h)
# this file obscures the system header
post-patch:
	${RM} -f ${WRKSRC}/../include/sys/queue.h
.endif

post-build:
	nroff -mandoc ${WRKSRC}/../docs/USD.doc/vi.man/vi.1 >${WRKSRC}/../docs/USD.doc/vi.man/vi.0

.include "../../mk/bsd.pkg.mk"
