# $NetBSD: Makefile,v 1.34 2008/01/18 05:09:39 tnn Exp $

.include	"../../security/nessus/Makefile.common"

DISTNAME=	nessus-plugins-GPL-${VERS}
PKGNAME=	nessus-plugins-${VERS}
PKGREVISION=	1
# nmap.nasl was removed from the pack,
# http://www.nessus.org/documentation/?doc=nmap-usage
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX} nmap.nasl
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
SITES.nmap.nasl=	http://www.nessus.org/documentation/

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
GNU_CONFIGURE=	yes
USE_TOOLS+=	cat gzip

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q} GZIP=${TOOLS_GZIP_CMD:Q} \
			ac_cv_path_MAKE=${MAKE:Q}

PLIST_SRC=	${WRKDIR}/PLIST PLIST

post-install:
	${INSTALL_DATA} ${DISTDIR}/nmap.nasl ${PREFIX}/lib/nessus/plugins/
	# auto-generate PLIST of plug-ins
	${RM} -f ${WRKDIR}/PLIST
	cd ${PREFIX} && \
	${FIND} lib/nessus/plugins -type f -print >>${WRKDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

.if !empty(UNPRIVILEGED:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-install=${ROOT_USER}
.endif

.include "../../security/nessus-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
