# $NetBSD: Makefile,v 1.23 2001/02/16 14:38:29 wiz Exp $
#

DISTNAME=		texinfo-3.12
PKGNAME=		gtexinfo-3.12
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=texinfo/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/texinfo/texinfo.html
COMMENT=		GNU info file manipulation utilities

.include "../../mk/bsd.prefs.mk"
.if (${OPSYS} == "SunOS")
DEPENDS+=		zlib-1.*:../zlib
CFLAGS+=		-I${PREFIX}/include             # zlib.h
.endif

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-catgets
PLIST_SRC=      	${WRKDIR}/.PLIST_SRC

.if exists(/usr/bin/install-info)
IGNORE=			"${PKGNAME} is included with your NetBSD distribution"
.endif

post-patch:
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
	${CAT} ${PKGDIR}/PLIST.common ${PKGDIR}/PLIST.${LOWER_OPSYS} > ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
