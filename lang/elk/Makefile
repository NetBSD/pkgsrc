# $NetBSD: Makefile,v 1.33 2006/03/04 21:29:53 jlam Exp $

DISTNAME=		elk-3.99.6
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://sam.zoy.org/elk/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/elk/
COMMENT=		Embeddable Scheme interpreter

GNU_CONFIGURE=yes
USE_LIBTOOL=  yes

CONFIGURE_ENV+=		WITH_XAW=${ELK_AWK:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
