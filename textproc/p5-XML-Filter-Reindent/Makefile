# $NetBSD: Makefile,v 1.12 2011/08/14 15:14:17 obache Exp $

DISTNAME=	XML-Filter-Reindent-0.03
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-Reindent-0.03/
COMMENT=	Reformats whitespace for pretty printing XML

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-Filter-DetectWS>=0.01:../../textproc/p5-XML-Filter-DetectWS

PERL5_PACKLIST=	auto/XML/Filter/Reindent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
