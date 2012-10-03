# $NetBSD: Makefile,v 1.11 2012/10/03 21:56:44 wiz Exp $
#

DISTNAME=	loco-0.32
PKGREVISION=	1
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
