# $NetBSD: Makefile,v 1.34 2006/06/02 16:39:15 joerg Exp $

DISTNAME=		elk-3.99.6
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://sam.zoy.org/elk/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/elk/
COMMENT=		Embeddable Scheme interpreter

GNU_CONFIGURE=yes
USE_LIBTOOL=  yes

USE_LANGUAGES=		c c++

CONFIGURE_ENV+=		WITH_XAW=${ELK_AWK:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
