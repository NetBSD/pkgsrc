# $NetBSD: Makefile,v 1.20 2024/04/26 15:42:53 wiz Exp $

DISTNAME=	opus-1.5.2
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	Totally open, royalty-free, highly versatile audio codec library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	perl-[0-9]*:../../lang/perl5

SUPERSEDES=	opus<=1.0.2

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	opus.pc.in

REPLACE_PERL+=	celt/arm/arm2gnu.pl

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
