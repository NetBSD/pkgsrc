# $NetBSD: Makefile,v 1.3 1999/07/06 07:57:20 jlam Exp $
#

DISTNAME=		latestCDK
PKGNAME=		cdk-4.9.8
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.vexus.ca/release/
EXTRACT_SUFX=		.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.vexus.ca/CDK.html

BUILD_DEPENDS+=		autoconf:../../devel/autoconf
DEPENDS+=		ncurses-4.2:../../devel/ncurses

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-I${LOCALBASE}/include	# for ncurses.h
CONFIGURE_ENV+=		CPPFLAGS="${CPPFLAGS}"

ALL_TARGET=		default

pre-configure:
	( cd ${WRKSRC}; autoconf )

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cdk
	for file in \
		alphalist_ex.c bind_ex.c buttonbox_ex.c calendar_ex.c \
		cdkscreen_ex.c dialog_ex.c entry_ex.c fselect_ex.c \
		graph_ex.c hello_ex.c histogram_ex.c itemlist_ex.c \
		label_ex.c marquee_ex.c matrix_ex.c mentry_ex.c menu_ex.c \
		position_ex.c preprocess_ex.c radio_ex.c scale_ex.c \
		scroll_ex.c selection_ex.c slider_ex.c subwindow_ex.c \
		swindow_ex.c template_ex.c tst.c viewer_ex.c vinstall.c; do \
		${INSTALL_DATA} ${WRKSRC}/examples/$${file} \
			${PREFIX}/share/examples/cdk/; \
	done

.include "../../mk/bsd.pkg.mk"
