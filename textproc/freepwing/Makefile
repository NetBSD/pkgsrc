# $NetBSD: Makefile,v 1.6 2005/03/06 03:25:13 uebayasi Exp $

DISTNAME=	freepwing-1.4.4
PKGREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/freepwing/
COMMENT=	Free JIS X 4081 (subset of EPWING V1) formatter

DEPENDS+=	p5-Jcode-[0-9]*:../../converters/p5-Jcode

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pkgdocdir=${PREFIX}/share/doc/freepwing
USE_GNU_TOOLS+=	make
USE_PERL5=	yes

.include "../../mk/bsd.pkg.mk"
