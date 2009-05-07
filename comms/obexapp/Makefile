# $NetBSD: Makefile,v 1.18 2009/05/07 17:59:37 plunky Exp $
#

DISTNAME=	obexapp-1.4.11
CATEGORIES=	comms
MASTER_SITES=	http://www.geocities.com/m_evmenkin/

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://www.geocities.com/m_evmenkin/
COMMENT=	Obex application to transfer objects to mobile equipment

LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-[4-9].*-*

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/cat1
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
OWN_DIRS+=		${VARBASE}/spool/obex

RCD_SCRIPTS+=		obexapp

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile obexapp.1 obexapp.h
SUBST_STAGE.paths=	post-configure
SUBST_SED.paths+=	-e "s|/usr/local/man|${PREFIX}|"
SUBST_SED.paths+=	-e "s|/usr/local|${PREFIX}|"
SUBST_SED.paths+=	-e "s|/var|${VARBASE}|"

# Sigh, this needs the GNU libiconv.
USE_GNU_ICONV=		yes
USE_BSD_MAKEFILE=	yes

# (work in progress) make sure it uses old SDP API
CPPFLAGS+=	-DSDP_COMPAT

# because the directory name conflicts with the rc.d script
post-extract:
	mv ${WRKDIR}/obexapp ${WRKDIR}/${DISTNAME}

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
