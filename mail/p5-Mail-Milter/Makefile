# $NetBSD: Makefile,v 1.13 2010/08/21 16:35:07 seb Exp $
#

DISTNAME=	Mail-Milter-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/} \
		${MASTER_SITE_SOURCEFORGE:=pmilter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pmilter.sourceforge.net/
COMMENT=	Sendmail::Milter enhancement API modules

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Sendmail-PMilter>=0.90:../../mail/p5-Sendmail-PMilter

PERL5_PACKLIST=	auto/Mail/Milter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
