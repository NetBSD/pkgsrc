# $NetBSD: Makefile,v 1.9 2015/08/18 07:31:04 wiz Exp $

DISTNAME=	tn3270-0.20100116
PKGREVISION=	2
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
