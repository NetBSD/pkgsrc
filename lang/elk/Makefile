# $NetBSD: Makefile,v 1.39 2008/11/10 17:21:36 wiz Exp $

DISTNAME=	elk-3.99.7
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://sam.zoy.org/elk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sam.zoy.org/elk/
COMMENT=	Embeddable Scheme interpreter

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
