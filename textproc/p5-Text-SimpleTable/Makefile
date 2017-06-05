# $NetBSD: Makefile,v 1.18 2017/06/05 14:24:51 ryoon Exp $

DISTNAME=	Text-SimpleTable-2.03
PKGNAME=	p5-${DISTNAME:S/01/0.1/}
PKGREVISION=	8
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
