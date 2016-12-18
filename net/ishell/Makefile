# $NetBSD: Makefile,v 1.11 2016/12/18 16:40:20 rillig Exp $
#

DISTNAME=	ish-v${VERSION}
PKGNAME=	ishell-${VERSION}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=icmpshell/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://icmpshell.sourceforge.net/
COMMENT=	Allow remote shell using ICMP

VERSION=	0.2
WRKSRC=		${WRKDIR}/ISHELL-v${VERSION}/

USE_TOOLS+=	gmake
NO_CONFIGURE=	yes

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:Q}

INSTALLATION_DIRS=	bin sbin

.include "../../mk/bsd.pkg.mk"
