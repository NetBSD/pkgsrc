# $NetBSD: Makefile,v 1.2 2001/09/12 06:47:16 jlam Exp $

DISTNAME=	reed-4.6
CATEGORIES=	misc
MASTER_SITES=	http://www.sacredchao.net/software/reed/

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://www.sacredchao.net/software/reed/index.shtml
COMMENT=	auto-scrolling file viewer

GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES
REPLACE_PERL=		scripts/breed scripts/wrap

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
