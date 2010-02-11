# $NetBSD: Makefile,v 1.7 2010/02/11 22:04:09 joerg Exp $
#

DISTNAME=		lft-2.2
CATEGORIES=		net
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mainnerve.com/lft/
COMMENT=		Layer four traceroute capable of tracing protocol paths

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lft ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lft.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
