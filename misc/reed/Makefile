# $NetBSD: Makefile,v 1.3 2001/12/25 15:51:15 wiz Exp $

DISTNAME=	reed-4.6
CATEGORIES=	misc
MASTER_SITES=	http://www.sacredchao.net/software/reed/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.sacredchao.net/software/reed/index.shtml
COMMENT=	auto-scrolling file viewer

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
REPLACE_PERL=		scripts/breed scripts/wrap

INCOMPAT_CURSES=	1.5 1.5.* 1.5[A-U]

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
