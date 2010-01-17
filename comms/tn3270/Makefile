# $NetBSD: Makefile,v 1.4 2010/01/17 18:26:28 spz Exp $

DISTNAME=	tn3270-0.20100116
CATEGORIES=	comms net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Utilities for connecting to IBM VM/CMS systems

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS+=	bin share/tn3270

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
