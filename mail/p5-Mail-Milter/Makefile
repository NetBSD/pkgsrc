# $NetBSD: Makefile,v 1.29 2022/06/28 11:34:29 wiz Exp $
#

DISTNAME=	Mail-Milter-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=pmilter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pmilter.sourceforge.net/
COMMENT=	Sendmail::Milter enhancement API modules

DEPENDS+=	p5-Sendmail-PMilter>=0.90:../../mail/p5-Sendmail-PMilter

PERL5_PACKLIST=	auto/Mail/Milter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
