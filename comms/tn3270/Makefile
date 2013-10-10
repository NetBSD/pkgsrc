# $NetBSD: Makefile,v 1.8 2013/10/10 16:31:28 roy Exp $

DISTNAME=	tn3270-0.20100116
PKGREVISION=	1
CATEGORIES=	comms net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Utilities for connecting to IBM VM/CMS systems

LICENSE=	modified-bsd

USE_TOOLS+=	yacc

LIBS+=		${BUILDLINK_LDADD.termcap}
MAKE_ENV+=	LIBS=${LIBS:Q}

INSTALLATION_DIRS+=	bin share/tn3270

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
