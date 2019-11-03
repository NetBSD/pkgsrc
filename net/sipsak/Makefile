# $NetBSD: Makefile,v 1.17 2019/11/03 11:45:53 rillig Exp $

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
SUBST_CLASSES+=		inline
SUBST_STAGE.inline=	pre-configure
SUBST_FILES.inline=	header_f.h header_f.c
SUBST_SED.inline=	-e 's/^inline //g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
