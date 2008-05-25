# $NetBSD: Makefile,v 1.11 2008/05/25 21:23:26 wiz Exp $
#

DISTNAME=	obexapp-1.4.7
CATEGORIES=	comms
MASTER_SITES=	http://www.geocities.com/m_evmenkin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/m_evmenkin/
COMMENT=	Obex application to transfer objects to mobile equipment

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-[4-9].*-*

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

# because the directory name conflicts with the rc.d script
post-extract:
	mv ${WRKDIR}/obexapp ${WRKDIR}/${DISTNAME}

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
