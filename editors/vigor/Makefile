# $NetBSD: Makefile,v 1.20 2005/06/19 17:40:22 kristerw Exp $
#

DISTNAME=	vigor-0.016
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vigor/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://vigor.sourceforge.net/
COMMENT=	nvi with excessive online "help"

CONFLICTS+=	nvi-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME}/build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-x
#		--enable-perlinterp \
#		--disable-curses \
#		--disable-db \
#		--disable-re
CONFIGURE_ENV+=	TCLCONFIG_SH=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=	vi_cv_path_shell="${TOOLS_SH}"
USE_TOOLS+=	sh

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
