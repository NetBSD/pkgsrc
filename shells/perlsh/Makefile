# $NetBSD: Makefile,v 1.1.1.1 2003/04/20 16:27:04 cjep Exp $
# Cjep: Makefile,v 1.3 2003/04/20 16:21:44 cjep Exp 

DISTNAME=	psh-1.8
PKGNAME=	perlsh-1.8
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.gregorpurdy.com/gregor/psh/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gregorpurdy.com/gregor/psh/
COMMENT=	The Perl Shell

DEPENDS+=	p5-Term-ReadLine>=1.12:../../devel/p5-Term-ReadLine

USE_BUILDLINK2=	yes
PKG_SHELL=	${PREFIX}/bin/psh

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/psh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
