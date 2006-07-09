# $NetBSD: Makefile,v 1.3 2006/07/09 16:35:31 xtraeme Exp $
#

DISTNAME=	obexapp-1.4.4
CATEGORIES=	comms
MASTER_SITES=	http://www.geocities.com/m_evmenkin/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.geocities.com/m_evmenkin/
COMMENT=	Obex application to transfer objects to mobile equipment

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-*

WRKSRC=		${WRKDIR}/obexapp

SUBST_CLASSES+=		mk
SUBST_FILES.mk=		Makefile
SUBST_STAGE.mk=		post-configure
SUBST_SED.mk=		-e "s|-lbsdxml|-lexpat|"
SUBST_SED.mk+=		-e "s|/usr/local/man|${PREFIX}|"
SUBST_SED.mk+=		-e "s|/usr/local|${PREFIX}|"
SUBST_SED.mk+=		-e "s|CFLAGS=|CFLAGS+=|"

# Sigh, this needs the GNU libiconv.
USE_GNU_ICONV=		yes

# Sigh... too many warnings with GCC 4.x, disable them for now.
CFLAGS+=		-w

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
