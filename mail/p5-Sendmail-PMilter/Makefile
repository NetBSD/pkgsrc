# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:22 tv Exp $
#

DISTNAME=	Sendmail-PMilter-0.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmilter/}

MAINTAINER=	tv@duh.org
HOMEPAGE=	http://pmilter.sourceforge.net/
COMMENT=	Pure-Perl Milter protocol API

# Though it doesn't exist yet, just in case:
CONFLICTS+=	p5-Sendmail-Milter-[0-9]*

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Sendmail/PMilter/.packlist
PERL5_REQD+=	5.6.0

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
