# $NetBSD: Makefile,v 1.15 2004/10/03 00:18:11 tv Exp $

DISTNAME=	nessus-plugins-${VERS}
PKGREVISION=	1
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

PLIST_SRC=	${WRKDIR}/PLIST PLIST

# auto-generate PLIST of plug-ins
post-install:
	${RM} -f ${WRKDIR}/PLIST
	cd ${PREFIX} && \
	${FIND} lib/nessus/plugins -type f -print >>${WRKDIR}/PLIST

.include "../../security/nessus-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
