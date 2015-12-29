# $NetBSD: Makefile,v 1.2 2015/12/29 14:40:20 bsiegert Exp $

DISTNAME=	pcre2-10.20
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/programming/pcre/ \
		${MASTER_SITE_SOURCEFORGE:=pcre/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pcre.org/
COMMENT=	Perl Compatible Regular Expressions library (major version 2)
LICENSE=	modified-bsd

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libpcre2-16.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-posix.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-8.pc.in
PKGCONFIG_OVERRIDE+=	libpcre2-32.pc.in

TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
