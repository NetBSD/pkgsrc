# $NetBSD: Makefile,v 1.8 1998/05/08 23:30:05 hubertf Exp $
# FreeBSD Id: Makefile,v 1.16 1997/11/30 19:37:48 vanilla Exp
#

DISTNAME=		mc-4.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/file/managers/mc

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-ncurses --without-edit --without-subshell
DEPENDS+=		ncurses-1.9.9g:../../devel/ncurses

MAN1=			mc.1 mcedit.1
MAN8=			mcserv.8

pre-configure:
	for f in `find ${WRKDIR}/. -type f -print|xargs ${GREP} -l '/usr/local'`; do \
		echo patching $$f ; \
		${CP} -p $$f $$f.tmp ; \
		${SED} -e 's:/usr/local:'${PREFIX}':g' < $$f.tmp > $$f && ${MV} $$f.tmp $$f; \
	done

post-install:
	@ ${RMDIR} ${PREFIX}/lib/mc/icons

.include "../../mk/bsd.pkg.mk"
