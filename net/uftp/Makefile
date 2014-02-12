# $NetBSD: Makefile,v 1.2 2014/02/12 23:18:26 tron Exp $

DISTNAME=	uftp-4.1.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://sourceforge.net/projects/uftp-multicast/files/source-tar/
EXTRACT_SUFX=	.tar
USE_TOOLS+=		gmake
NO_CONFIGURE=	yes
MAKE_FILE=		makefile

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://uftp-multicast.sourceforge.net/
COMMENT=	UFTP is an encrypted multicast file transfer program
LICENSE=	gnu-gpl-v3

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
