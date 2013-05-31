# $NetBSD: Makefile,v 1.6 2013/05/31 12:39:58 wiz Exp $

DISTNAME=	ctemplate-2.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://google-ctemplate.googlecode.com/files/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/google-ctemplate/
COMMENT=	Simple but powerful template language for C++
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	libctemplate.pc
PKGCONFIG_OVERRIDE+=	libctemplate_nothreads.pc
PKGCONFIG_OVERRIDE_STAGE=post-build
REPLACE_PERL=		src/template-converter

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
