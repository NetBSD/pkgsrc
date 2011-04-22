# $NetBSD: Makefile,v 1.44 2011/04/22 13:44:36 obache Exp $

.include	"../../security/nessus/Makefile.common"

DISTNAME=	nessus-plugins-GPL-${VERS}
PKGNAME=	nessus-plugins-${VERS}
PKGREVISION=	8
# nmap.nasl was removed from the pack,
# http://www.nessus.org/documentation/?doc=nmap-usage
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} nmap.nasl
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
SITES.nmap.nasl=	http://www.nessus.org/documentation/

COMMENT=	Plugins for the Nessus Network Security Scanner

FETCH_MESSAGE+=	"Please download nmap.nasl"
FETCH_MESSAGE+=	"manually from ${SITES.nmap.nasl:Q}"

DEPENDS+=	nmap>=2.0:../../net/nmap

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/nessus-plugins
GNU_CONFIGURE=		yes
USE_TOOLS+=		cat gzip
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q} GZIP=${TOOLS_GZIP_CMD:Q} \
			ac_cv_path_MAKE=${MAKE:Q}

PLIST_SRC=	${WRKDIR}/PLIST PLIST

post-install:
	${INSTALL_DATA} ${DISTDIR}/nmap.nasl ${DESTDIR}${PREFIX}/lib/nessus/plugins/
	# auto-generate PLIST of plug-ins
	${RM} -f ${WRKDIR}/PLIST
	cd ${DESTDIR}${PREFIX} && \
	${FIND} lib/nessus/plugins -type f -print >>${WRKDIR}/PLIST

CONFIGURE_ARGS+=	--enable-install=${ROOT_USER}

.include "../../security/nessus-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
