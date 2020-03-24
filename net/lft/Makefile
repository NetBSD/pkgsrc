# $NetBSD: Makefile,v 1.14 2020/03/24 14:40:56 nia Exp $

DISTNAME=	lft-3.8
PKGNAME=	lft-3.80
CATEGORIES=	net
MASTER_SITES=	http://pwhois.org/dl/index.who?file=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pwhois.org/lft/
COMMENT=	Layer four traceroute capable of tracing protocol paths
LICENSE=	lft-license

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lft ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lft.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
