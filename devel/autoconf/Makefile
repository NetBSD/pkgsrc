# New ports collection makefile for:	autoconf
# Version required:     2.12
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $NetBSD: Makefile,v 1.10 1998/03/11 23:18:46 agc Exp $
# FreeBSD Id: Makefile,v 1.12 1997/06/13 20:00:47 max Exp
#

DISTNAME=       autoconf-2.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

BUILD_DEPENDS=	${PREFIX}/bin/install-info:${PORTSDIR}/devel/gtexinfo
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	M4=${PREFIX}/bin/gm4

PLIST_SRC=	${WRKDIR}/PLIST-src

post-install:
	@(ex='s|@HaveAutoscan@||';			\
	if [ ! -f ${WRKSRC}/autoscan ]; then		\
		ex='/@HaveAutoscan@/d';			\
	fi;						\
	${SED} -e "$$ex" < ${PKGDIR}/PLIST > ${PLIST_SRC})
	@install-info ${PREFIX}/info/autoconf.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/standards.info ${PREFIX}/info/dir

.include <bsd.port.mk>
