# $NetBSD: Makefile,v 1.8 2017/02/20 09:44:34 wiz Exp $

DISTNAME=	pcre2-10.23
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=pcre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library (major version 2)
LICENSE=	modified-bsd

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-jit

PKGCONFIG_OVERRIDE+=	libpcre2-16.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-posix.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-8.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-32.pc.in

CONFIGURE_ARGS+=	--enable-pcre2-16
CONFIGURE_ARGS+=	--enable-pcre2-32
CONFIGURE_ARGS+=	--enable-pcre2grep-libz
CONFIGURE_ARGS+=	--enable-pcre2grep-libbz2

TEST_TARGET=		check

NOT_PAX_MPROTECT_SAFE=	bin/pcre2grep bin/pcre2test

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
