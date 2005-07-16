# $NetBSD: Makefile,v 1.9 2005/07/16 01:19:23 jlam Exp $

DISTNAME=	freepwing-1.4.4
PKGREVISION=	2
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/freepwing/
COMMENT=	Free JIS X 4081 (subset of EPWING V1) formatter

DEPENDS+=	p5-Jcode-[0-9]*:../../converters/p5-Jcode

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pkgdocdir=${PREFIX}/share/doc/freepwing
CONFIGURE_ENV+=	GNUMAKE="${GMAKE}"
USE_TOOLS+=	gmake perl:run

.include "../../mk/bsd.pkg.mk"
