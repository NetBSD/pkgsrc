# $NetBSD: Makefile,v 1.27 2015/08/18 07:31:05 wiz Exp $
#

DISTNAME=	bvi-1.3.2.src
PKGNAME=	bvi-1.3.2
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
LIBS+=		${BUILDLINK_LDADD.termcap}
MAKE_ENV+=	SHELL=${SH:Q}

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
