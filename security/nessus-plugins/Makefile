# $NetBSD: Makefile,v 1.16 2004/11/02 00:04:03 adrianp Exp $

DISTNAME=	nessus-plugins-${VERS}
.include	"../nessus/Makefile.common"

COMMENT=	Plugins for the Nessus Network Security Scanner

DEPENDS+=	nmap>=2.0:../../net/nmap

WRKSRC=		${WRKDIR}/nessus-plugins
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-fetchcmd=/usr/bin/ftp
.else
CONFIGURE_ARGS+=	--with-fetchcmd=${PREFIX}/bin/ftp
.endif

SUBST_CLASSES+=		fetch
SUBST_STAGE.fetch=	post-configure
SUBST_FILES.fetch=	nessus-update-plugins
SUBST_SED.fetch=	-e "s|fetch_args=\"\"|fetch_args=\"-o -\"|g"
SUBST_MESSAGE.fetch=	"Fixing fetch parameters."

PLIST_SRC=	${WRKDIR}/PLIST PLIST

# auto-generate PLIST of plug-ins
post-install:
	${RM} -f ${WRKDIR}/PLIST
	cd ${PREFIX} && \
	${FIND} lib/nessus/plugins -type f -print >>${WRKDIR}/PLIST

.include "../../security/nessus-core/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
