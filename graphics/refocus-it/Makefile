# $NetBSD: Makefile,v 1.2 2005/01/21 23:01:09 kristerw Exp $
#

DISTNAME=		refocus-it-2.0.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=refocus-it/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://refocus-it.sourceforge.net/
COMMENT=		Refocus images

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_PERL5=		build
#just build the command line tool
CONFIGURE_ARGS+=	--without-gimp

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
