# $NetBSD: Makefile,v 1.1.1.1 2003/12/17 06:25:44 grant Exp $
#

DISTNAME=	File-DirSync-1.11
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module to syncronize two directories rapidly

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/DirSync/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
