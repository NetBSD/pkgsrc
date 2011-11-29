# $NetBSD: Makefile,v 1.10 2011/11/29 17:49:57 hans Exp $
#

DISTNAME=	loco-0.32
CATEGORIES=	misc
MASTER_SITES=	http://zjuul.net/~jules/loco/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zjuul.net/~jules/loco/
COMMENT=	Colorize file or standard input and print on the standard output

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl:run pod2man pod2html
REPLACE_PERL=	loco

BUILD_TARGET=	# defined

.include "../../mk/bsd.pkg.mk"
