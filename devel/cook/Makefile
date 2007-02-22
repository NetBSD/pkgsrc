# $NetBSD: Makefile,v 1.18 2007/02/22 19:01:17 wiz Exp $

DISTNAME=	cook-2.26
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://miller.emu.id.au/pmiller/software/cook/

MAINTAINER=	groo@NetBSD.org
HOMEPAGE=	http://miller.emu.id.au/pmiller/software/cook/
COMMENT=	More powerful replacement for the traditional make(1) tool

USE_TOOLS+=	msgfmt yacc perl:run
GNU_CONFIGURE=	yes

REPLACE_PERL=	bin/cook_rsh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
