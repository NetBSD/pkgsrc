# $NetBSD: Makefile,v 1.18 2012/10/31 11:17:21 asau Exp $

DISTNAME=	libsmi-0.4.8
PKGREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.ibr.cs.tu-bs.de/pub/local/libsmi/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ibr.cs.tu-bs.de/projects/libsmi/
COMMENT=	Library to access SMI MIB information

MIBDIR=		${PREFIX}/share/libsmi/mibs
PIBDIR=		${PREFIX}/share/libsmi/pibs

DEPENDS+=	wget-[0-9]*:../../net/wget

USE_LIBTOOL=	YES
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-mibdir=${MIBDIR:Q}
CONFIGURE_ARGS+=--with-pibdir=${PIBDIR:Q}
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}

REPLACE_SH+=	tools/smicache.in
REPLACE_SH+=	tools/smistrip.in
REPLACE_SH+=	test/*.test.in

TEST_TARGET=	check

post-extract:
	rm -f ${WRKSRC}/test/smilint-smiv2.test

.include "../../mk/bsd.pkg.mk"
