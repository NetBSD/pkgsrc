# $NetBSD: Makefile,v 1.25 2013/10/10 08:56:34 apb Exp $
#

DISTNAME=	bvi-1.3.2.src
PKGNAME=	bvi-1.3.2
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
LIBS+=		${BUILDLINK_LDADD.termcap}
MAKE_ENV+=	SHELL=${SH:Q}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
