# $NetBSD: Makefile,v 1.13 2008/07/28 18:49:06 plunky Exp $
#

DISTNAME=	obexapp-1.4.9
CATEGORIES=	comms
MASTER_SITES=	http://www.geocities.com/m_evmenkin/

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://www.geocities.com/m_evmenkin/
COMMENT=	Obex application to transfer objects to mobile equipment

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-[4-9].*-*

BUILD_DEFS+=		VARBASE

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

# because the directory name conflicts with the rc.d script
post-extract:
	mv ${WRKDIR}/obexapp ${WRKDIR}/${DISTNAME}

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
