# $NetBSD: Makefile,v 1.11 2020/05/27 19:37:43 wiz Exp $

DISTNAME=	crush-tools-2013-04
PKGNAME=	${DISTNAME:C/-([0-9]+)$/.\1/}
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://crush-tools.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google/crush-tools
COMMENT=	Collection of tools for processing delimited-text data
LICENSE=	apache-2.0

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc
#DEPENDS+=	{perl>=5,p5-Getopt-Long-[0-9]*}:../../devel/p5-Getopt-Long

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gm4 gmake perl

REPLACE_PERL+=	src/bin/genman.pl

CFLAGS.SunOS+=	-Du_int32_t=uint32_t

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
