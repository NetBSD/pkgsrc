# $NetBSD: Makefile,v 1.23 2008/06/12 02:14:29 joerg Exp $
#

DISTNAME=	bvi-1.3.2.src
PKGNAME=	bvi-1.3.2
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH:Q}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
