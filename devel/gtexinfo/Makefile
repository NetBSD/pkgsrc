# $NetBSD: Makefile,v 1.8 1998/05/14 11:09:47 agc Exp $
#

DISTNAME=		texinfo-3.12
PKGNAME=		gtexinfo-3.12
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU}

MAINTAINER=		packages@netbsd.org

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-catgets

pre-build:
	${MV} ${WRKSRC}/info/filesys.h ${WRKSRC}/info/filesys.h.bak
	${CAT} ${WRKSRC}/info/filesys.h.bak | \
		${SED} s/@PREFIX@/${PREFIX:S/\//\\\\\//g}/g | \
		${SED} s/@X11BASE@/${X11BASE:S/\//\\\\\//g}/g | \
		${SED} s/@LOCALBASE@/${LOCALBASE:S/\//\\\\\//g}/g \
		> ${WRKSRC}/info/filesys.h

post-install:
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/texinfo
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info.info
	${PREFIX}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/info-stnd.info

.include "../../mk/bsd.pkg.mk"
