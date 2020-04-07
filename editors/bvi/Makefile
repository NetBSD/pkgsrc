# $NetBSD: Makefile,v 1.32 2020/04/07 09:22:36 wiz Exp $

DISTNAME=	bvi-1.4.1.src
PKGNAME=	bvi-1.4.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	http://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH:Q}

LDFLAGS.NetBSD+=	-ltermcap # tgetstr()

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
