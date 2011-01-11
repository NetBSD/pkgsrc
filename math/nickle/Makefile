# $NetBSD: Makefile,v 1.9 2011/01/11 11:53:13 drochner Exp $
#

DISTNAME=	nickle-2.70
CATEGORIES=	math lang
MASTER_SITES=	http://nickle.org/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nickle.org/
COMMENT=	Desk calculator language
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

TEST_TARGET=	check

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
