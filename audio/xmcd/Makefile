# $NetBSD: Makefile,v 1.30 2002/01/10 20:56:25 tron Exp $

DISTNAME=	xmcd-3.0.2
CATEGORIES=	audio
MASTER_SITES=	http://www.ibiblio.org/tkan/download/xmcd/src/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.ibiblio.org/tkan/xmcd/
COMMENT=	Motif CD player

PATCH_SITES=		${HOMEPAGE}
PATCHFILES=		xmcd-3.0.2-proxyauth-patch
PATCH_DIST_STRIP=	-p1

WRKSRC=		${WRKDIR}/xmcd-3.0
USE_NCURSES=	yes
USE_IMAKE=	yes
IS_INTERACTIVE=	yes	# asks a lot of questions
MAKE_ENV+=	SHELL=${SH}

post-patch:
	cd ${WRKSRC} && \
	for f in libdi_d/config.sh misc_d/start.sh install.sh; do \
		${SED} -e "s/@MACHINE_ARCH@/${MACHINE_ARCH}/" $$f > $$f.new; \
		${MV} -f $$f.new $$f; \
	done

post-install:
.for FILE in cda xmcd gobrowser
	@${TEST} -n "${STRIPFLAG}" && \
	strip ${PREFIX}/lib/X11/xmcd/bin-${OPSYS}-${MACHINE_ARCH}/${FILE}
.endfor
	${MV} ${PREFIX}/man/cat1/cda.1 ${PREFIX}/man/man1/cda.1
	${MV} ${PREFIX}/man/cat1/xmcd.1 ${PREFIX}/man/man1/xmcd.1
.if ! defined(BATCH)
	${PREFIX}/lib/X11/xmcd/config/config.sh
.endif

.include "../../devel/ncurses/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
