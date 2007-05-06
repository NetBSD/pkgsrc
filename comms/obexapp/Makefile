# $NetBSD: Makefile,v 1.7 2007/05/06 08:33:54 xtraeme Exp $
#

DISTNAME=	obexapp-1.4.5
CATEGORIES=	comms
MASTER_SITES=	http://www.geocities.com/m_evmenkin/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.geocities.com/m_evmenkin/
COMMENT=	Obex application to transfer objects to mobile equipment

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-[4-9].*-*

OWN_DIRS+=		${VARBASE}/spool/obex

RCD_SCRIPTS+=		obexapp

SUBST_CLASSES+=		mk var
SUBST_FILES.mk=		Makefile
SUBST_STAGE.mk=		post-configure
SUBST_SED.mk=		-e "s|-lbsdxml|-lexpat|"
SUBST_SED.mk+=		-e "s|/usr/local/man|${PREFIX}|"
SUBST_SED.mk+=		-e "s|/usr/local|${PREFIX}|"
SUBST_SED.mk+=		-e "s|CFLAGS=|CFLAGS+=|"
SUBST_FILES.var=	obexapp.1 obexapp.h
SUBST_STAGE.var=	post-configure
SUBST_SED.var=		-e "s|/var|${VARBASE}|"

# Sigh, this needs the GNU libiconv.
USE_GNU_ICONV=		yes

# Too many warnings with gcc4, disable them for now.
BUILDLINK_TRANSFORM+=	rm:-Werror

# because the directory name conflicts with the rc.d script
post-extract:
	mv ${WRKDIR}/obexapp ${WRKDIR}/${DISTNAME}

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
