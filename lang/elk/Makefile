# $NetBSD: Makefile,v 1.42 2012/08/29 08:45:52 dholland Exp $

DISTNAME=	elk-3.99.8
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://sam.zoy.org/elk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sam.zoy.org/elk/
COMMENT=	Embeddable Scheme interpreter

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_TOOLS+=		groff
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
