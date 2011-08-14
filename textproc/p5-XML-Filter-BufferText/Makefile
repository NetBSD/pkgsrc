# $NetBSD: Makefile,v 1.12 2011/08/14 15:14:17 obache Exp $

DISTNAME=	XML-Filter-BufferText-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
#SVR4_PKGNAME=
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-BufferText/
COMMENT=	Perl5 module XML parser filter to put all characters() in one event

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-XML-SAX>=0.04:../../textproc/p5-XML-SAX

USE_LANGUAGES=		# empty
PERL5_PACKLIST=	auto/XML/Filter/BufferText/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
