# $NetBSD: Makefile,v 1.29 2006/04/17 13:46:47 wiz Exp $

.include	"../../security/nessus/Makefile.common"

DISTNAME=	nessus-plugins-GPL-${VERS}
PKGNAME=	nessus-plugins-${VERS}
PKGREVISION=	2

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
GNU_CONFIGURE=		yes
USE_TOOLS+=	cat gzip

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ENV+=		CAT=${TOOLS_CAT:Q} GZIP=${TOOLS_GZIP_CMD:Q}

PLIST_SRC=	${WRKDIR}/PLIST PLIST

# auto-generate PLIST of plug-ins
post-install:
	${RM} -f ${WRKDIR}/PLIST
	cd ${PREFIX} && \
	${FIND} lib/nessus/plugins -type f -print >>${WRKDIR}/PLIST

.include "../../security/nessus-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
