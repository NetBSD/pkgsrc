# $NetBSD: Makefile,v 1.6 2002/10/25 17:54:55 wiz Exp $

DISTNAME=	reed-4.6
CATEGORIES=	misc
MASTER_SITES=	http://www.sacredchao.net/software/reed/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.sacredchao.net/software/reed/index.shtml
COMMENT=	auto-scrolling file viewer

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PERL5=		YES
REPLACE_PERL=		scripts/breed scripts/wrap

# wgetnstr()
INCOMPAT_CURSES=	NetBSD-1.5-* NetBSD-1.5.*-* NetBSD-1.5[A-U]-*

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
