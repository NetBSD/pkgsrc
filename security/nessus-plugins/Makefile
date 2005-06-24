# $NetBSD: Makefile,v 1.22 2005/06/24 21:53:48 kristerw Exp $

.include	"../nessus/Makefile.common"

DISTNAME=	nessus-plugins-GPL-${VERS}
PKGREVISION=	1
PKGNAME=	nessus-plugins-${VERS}

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
GNU_CONFIGURE=		yes
USE_TOOLS+=	cat

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ENV+=		CAT="${TOOLS_CAT}"

PLIST_SRC=	${WRKDIR}/PLIST PLIST

# auto-generate PLIST of plug-ins
post-install:
	${RM} -f ${WRKDIR}/PLIST
	cd ${PREFIX} && \
	${FIND} lib/nessus/plugins -type f -print >>${WRKDIR}/PLIST

.include "../../security/nessus-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
