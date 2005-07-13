# $NetBSD: Makefile,v 1.9 2005/07/13 18:46:54 jlam Exp $

DISTNAME=      	Spiffy-0.24
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/${MODULE_DIR}/${AUTHOR_DIR}/}
MODULE_DIR=	modules/by-module
AUTHOR_DIR=	authors/id/I/IN/INGY

MAINTAINER=	jlam@NetBSD.org
COMMENT=	Object-oriented Perl framework

DEPENDS+=	p5-Filter-[0-9]*:../../textproc/p5-Filter

PERL5_PACKLIST=	auto/Spiffy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
