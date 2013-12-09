# $NetBSD: Makefile,v 1.24 2013/12/09 14:17:52 obache Exp $

DISTNAME=	psh-1.8
PKGNAME=	perlsh-1.8
PKGREVISION=	10
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.focusresearch.com/gregor/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.focusresearch.com/gregor/sw/psh/
COMMENT=	The Perl Shell

DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	{perl>=5.17.10,p5-Term-ReadLine>=1.12}:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-BSD-Resource>=1.15:../../devel/p5-BSD-Resource

PKG_SHELL=	bin/psh

PERL5_PACKLIST=	auto/psh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
