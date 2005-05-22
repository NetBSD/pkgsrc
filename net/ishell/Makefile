# $NetBSD: Makefile,v 1.3 2005/05/22 20:08:24 jlam Exp $
#

DISTNAME=	ish-v${VERSION}
PKGNAME=	ishell-${VERSION}
WRKSRC=		${WRKDIR}/ISHELL-v${VERSION}/
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpshell/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://icmpshell.sourceforge.net/
COMMENT=	Allow remote shell using ICMP

VERSION=	0.2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

MAKE_ENV+=	LIBS="${LIBS}"
LIBS.SunOS+=	-lsocket

INSTALLATION_DIRS=	bin sbin

.include "../../mk/bsd.pkg.mk"
