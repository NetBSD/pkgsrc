# $NetBSD: Makefile,v 1.1 2014/01/12 15:06:37 mspo Exp $
#

PKGNAME=	netcat-openbsd-1
CATEGORIES=	net
DISTNAME=	msporleder-netcat-openbsd-126d9bb
MASTER_SITES=	-https://codeload.github.com/msporleder/netcat-openbsd/legacy.tar.gz/126d9bb
FETCH_USING=	curl
#FETCH_OUTPUT_ARGS=	${DISTNAME}
LICENSE=		modified-bsd

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openbsd.org/
COMMENT=	Arbitrary TCP and UDP connections and listens
CONFLICTS=	netcat-[0-9]*

NO_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
