# $NetBSD: Makefile,v 1.31 2005/12/05 20:50:25 rillig Exp $

DISTNAME=		elk-3.99.6
CATEGORIES=		lang
MASTER_SITES=		http://sam.zoy.org/elk/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/elk/
COMMENT=		Embeddable Scheme interpreter

GNU_CONFIGURE=yes
USE_LIBTOOL=  yes

CONFIGURE_ENV+=		WITH_XAW=${ELK_AWK:Q}

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
