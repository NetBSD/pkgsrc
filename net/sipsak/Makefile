# $NetBSD: Makefile,v 1.20 2023/10/24 22:10:33 wiz Exp $

DISTNAME=	sipsak-0.9.8.1
MASTER_SITES=	https://github.com/nils-ohlmeier/sipsak/releases/download/${PKGVERSION_NOREV}/

PKGREVISION=	1
CATEGORIES=	net comms

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/sipsak.berlios/
COMMENT=	Sipsak is a command-line SIP testing utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
