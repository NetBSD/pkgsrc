# $NetBSD: Makefile,v 1.20 2018/06/10 13:57:37 wen Exp $

DISTNAME=	Text-SimpleTable-2.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-SimpleTable/
COMMENT=	Simple Eyecandy ASCII Tables
LICENSE=	artistic-2.0

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Text/SimpleTable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
