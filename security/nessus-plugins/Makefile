# $NetBSD: Makefile,v 1.19 2005/04/05 22:15:55 adrianp Exp $

.include	"../nessus/Makefile.common"

DISTNAME=	nessus-plugins-GPL-${VERS}
PKGNAME=	nessus-plugins-${VERS}

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

PLIST_SRC=	${WRKDIR}/PLIST PLIST

# auto-generate PLIST of plug-ins
post-install:
	${RM} -f ${WRKDIR}/PLIST
	cd ${PREFIX} && \
	${FIND} lib/nessus/plugins -type f -print >>${WRKDIR}/PLIST

.include "../../security/nessus-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
