# $NetBSD: Makefile,v 1.5 2005/03/05 10:39:10 uebayasi Exp $

DISTNAME=	freepwing-1.4.4
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/freepwing/
COMMENT=	Free JIS X 4081 (subset of EPWING V1) formatter

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pkgdocdir=${PREFIX}/share/doc/freepwing
USE_GNU_TOOLS+=	make
USE_PERL5=	yes

.include "../../mk/bsd.pkg.mk"
