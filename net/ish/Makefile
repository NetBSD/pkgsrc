# $NetBSD: Makefile,v 1.1.1.1 2004/04/11 23:48:26 minskim Exp $
#

DISTNAME=	ish-v${VERSION}
PKGNAME=	ish-${VERSION}
WRKSRC=		${WRKDIR}/ISHELL-v${VERSION}/
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpshell/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://icmpshell.sourceforge.net/
COMMENT=	Allow remote shell using ICMP

VERSION=	0.2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
NO_CONFIGURE=	yes

MAKE_ENV+=	LIBS="${LIBS}"
LIBS.SunOS+=	-lsocket

INSTALLATION_DIRS=	bin sbin

.include "../../mk/bsd.pkg.mk"
