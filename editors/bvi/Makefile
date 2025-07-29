# $NetBSD: Makefile,v 1.34 2025/07/29 16:26:07 tsutsui Exp $

DISTNAME=	bvi-1.5.0.src
PKGNAME=	${DISTNAME:S/.src//}
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
