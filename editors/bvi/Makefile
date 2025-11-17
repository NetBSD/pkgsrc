# $NetBSD: Makefile,v 1.35 2025/11/17 11:00:42 wiz Exp $

DISTNAME=	bvi-1.5.0.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bvi/}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://bvi.sourceforge.net/
COMMENT=	Vi-like editor for binary files

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES
MAKE_ENV+=	SHELL=${SH:Q}

LDFLAGS.NetBSD+=	-ltermcap # tgetstr()

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
