# $NetBSD: Makefile,v 1.3 2003/07/17 22:54:15 grant Exp $

DISTNAME=	freepwing-1.4.3
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/misc/freepwing/

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	http://www.sra.co.jp/people/m-kasahr/freepwing/
COMMENT=	Free JIS X 4081 (subset of EPWING V1) formatter

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pkgdocdir=${PREFIX}/share/doc/freepwing
USE_GMAKE=	yes
USE_PERL5=	yes

.include "../../mk/bsd.pkg.mk"
