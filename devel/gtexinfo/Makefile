# $NetBSD: Makefile,v 1.10 1998/06/14 21:29:39 cjs Exp $
#

DISTNAME=		texinfo-3.12
PKGNAME=		gtexinfo-3.12
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU}

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-catgets

pre-build:
	${MV} -f ${WRKSRC}/info/filesys.h ${WRKSRC}/info/filesys.h.orig
	${SED} -e 's|@PREFIX@|${PREFIX}|g'		\
		-e 's|@X11BASE@|${X11BASE}|g'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|g'	\
		< ${WRKSRC}/info/filesys.h.orig		\
		> ${WRKSRC}/info/filesys.h

post-install:
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/texinfo
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info.info
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info-stnd.info

.include "../../mk/bsd.pkg.mk"
