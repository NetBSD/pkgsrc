# $NetBSD: Makefile,v 1.12 2010/08/21 16:35:09 seb Exp $
#

DISTNAME=	Sendmail-PMilter-0.95
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pmilter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pmilter.sourceforge.net/
COMMENT=	Pure-Perl Milter protocol API

PKG_DESTDIR_SUPPORT=	user-destdir

# Though it doesn't exist yet, just in case:
CONFLICTS+=	p5-Sendmail-Milter-[0-9]*

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1

PERL5_PACKLIST=	auto/Sendmail/PMilter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
