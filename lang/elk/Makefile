# $NetBSD: Makefile,v 1.30 2005/10/15 23:07:21 tonio Exp $

DISTNAME=		elk-3.99.6
CATEGORIES=		lang
MASTER_SITES=		http://sam.zoy.org/elk/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sam.zoy.org/elk/
COMMENT=		Embeddable Scheme interpreter

GNU_CONFIGURE=yes
USE_LIBTOOL=  yes

CONFIGURE_ENV= WITH_XAW="${ELK_AWK}"

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
