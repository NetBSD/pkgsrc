# $NetBSD: Makefile,v 1.20 2004/10/03 00:13:32 tv Exp $

DISTNAME=	pcre-5.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/	\
		ftp://pcre.sourceforge.net/pub/pcre/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	proff@NetBSD.org
HOMEPAGE=	http://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKG_CONFIG_OVERRIDE=	libpcre.pc.in

TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
