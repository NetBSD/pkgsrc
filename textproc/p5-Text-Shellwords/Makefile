# $NetBSD: Makefile,v 1.2 2005/01/08 13:25:03 minskim Exp $
#

DISTNAME=		Text-Shellwords-1.02
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		textproc
MASTER_SITES=		http://www.cpan.org/authors/id/L/LD/LDS/

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://www.cpan.org/authors/id/L/LD/LDS/
COMMENT=		Wrapper around shellwords.pl package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Text/Shellwords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
