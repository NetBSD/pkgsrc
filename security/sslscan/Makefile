# $NetBSD: Makefile,v 1.5 2015/10/11 10:56:44 tron Exp $

DISTNAME=	sslscan-1.8.2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sslscan/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/sslscan/
COMMENT=	Fast SSL Scanner
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-install:
	${RM} -f ${WRKSRC}/INSTALL

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
