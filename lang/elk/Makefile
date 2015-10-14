# $NetBSD: Makefile,v 1.45 2015/10/14 20:17:27 wiz Exp $

DISTNAME=	elk-3.99.8
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://sam.zoy.org/elk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sam.zoy.org/elk/
COMMENT=	Embeddable Scheme interpreter

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		groff
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIG_GUESS_OVERRIDE+=	.auto/config.guess
CONFIG_SUB_OVERRIDE+=	.auto/config.sub

.include "options.mk"

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
