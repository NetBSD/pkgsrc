# $NetBSD: Makefile,v 1.5 2004/02/14 17:21:53 jlam Exp $
#

DISTNAME=	aiksaurus-1.0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aiksaurus/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://aiksaurus.sourceforge.net/
COMMENT=	English-language thesaurus

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=		--without-gtk
PKGCONFIG_OVERRIDE=	${WRKSRC}/base/aiksaurus-1.0.pc.in

.include "../../mk/bsd.pkg.mk"
