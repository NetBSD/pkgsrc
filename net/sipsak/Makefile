# $NetBSD: Makefile,v 1.15 2017/04/29 10:21:54 schwarz Exp $

DISTNAME=	sipsak-0.9.6-1
PKGNAME=	${DISTNAME:S/-1//}
PKGREVISION=	7
CATEGORIES=	net comms
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sipsak.berlios/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/sipsak.berlios/
COMMENT=	Sipsak is a command-line SIP testing utility
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${DISTNAME:S/-1//}

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

# get rid of inline
SUBST_CLASSES+=	inline
SUBST_STAGE.inline=	post-patch
SUBST_FILES.inline=	header_f.h header_f.c
SUBST_SED.inline=	-e 's/^inline //g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
