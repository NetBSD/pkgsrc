# $NetBSD: Makefile,v 1.33 2023/03/10 21:56:18 ryoon Exp $

DISTNAME=	bvi-1.4.2.src
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
