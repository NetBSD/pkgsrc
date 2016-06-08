# $NetBSD: Makefile,v 1.43 2016/06/08 19:22:16 wiz Exp $
#

DISTNAME=	epic4-2.10.2
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.epicsol.org/pub/epic/EPIC4-PRODUCTION/ \
		ftp://totem.fix.no/pub/mirrors/epic/EPIC4-PRODUCTION/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.epicsol.org/
COMMENT=	The (E)nhanced (P)rogrammable (I)RC-II (C)lient

GNU_CONFIGURE=	YES

INSTALL_MAKE_FLAGS+=	IP=${DESTDIR}

CFLAGS.OSF1+=	-D_SOCKADDR_LEN

.include "options.mk"

.include "../../mk/termcap.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
