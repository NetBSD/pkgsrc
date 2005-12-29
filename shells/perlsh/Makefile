# $NetBSD: Makefile,v 1.13 2005/12/29 06:22:12 jlam Exp $
# Cjep: Makefile,v 1.3 2003/04/20 16:21:44 cjep Exp

DISTNAME=	psh-1.8
PKGNAME=	perlsh-1.8
PKGREVISION=	3
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.gregorpurdy.com/gregor/psh/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gregorpurdy.com/gregor/psh/
COMMENT=	The Perl Shell

DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Term-ReadLine>=1.12:../../devel/p5-Term-ReadLine
DEPENDS+=	p5-BSD-Resource>=1.15:../../devel/p5-BSD-Resource

PKG_SHELL=	bin/psh

PERL5_PACKLIST=	auto/psh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
